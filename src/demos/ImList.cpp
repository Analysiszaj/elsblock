#include "imgui.h"
#include "ImList.h"
#include "common.h"

namespace ImList
{

    bool SmoothMenuWindow::DrawMenuWindow(
        const char *name,
        const std::vector<std::string> &items,
        uint32_t &count,
        const ImVec4 &color,
        const ImVec2 &size,
        float speed,
        float text_scale)
    {
        ImGui::BeginChild(name, size);

        ListDrawRectangleFill(ImVec2(), size, ColorBrightnesScale(color, 0.65f));
        ImGui::SetWindowFontScale(text_scale);

        if (ImGui::IsWindowHovered())
        {
            DrawMenuTypeRect(TextDrawHeight, ColorBrightnesScale(color, 0.32f));
        }
        DrawMenuItemRect(TextDrawHeight, ColorBrightnesScale(color, 0.42f));

        bool ReturnTypeFlag = false;
        for (size_t i = 0; i < items.size(); ++i)
        {
            ImVec2 ItemTextSize = ImGui::CalcTextSize(items[i].c_str());
            float DrawHeightPosition = ImGui::GetCursorPosY();

            ImGui::SetCursorPosX(ItemCenteredCalc(ItemTextSize.x));
            ImGui::Text(items[i].c_str());
            if (ImGui::IsItemHovered())
            {
                menu_buffer_item_scroll.x = DrawHeightPosition - ImGui::GetScrollY();
                menu_buffer_width_type.x = ItemTextSize.x + IMGUI_ITEM_SPAC * 2.0f;

                if (ImGui::GetMouseClickedCount(0))
                {
                    count = (uint32_t)i;
                    ReturnTypeFlag = true;
                }
            }
            if (count == (uint32_t)i)
            {
                menu_buffer_item_scroll.x = DrawHeightPosition - ImGui::GetScrollY();
                menu_buffer_width_item.x = ItemTextSize.x + IMGUI_ITEM_SPAC * 2.0f;
            }
            TextDrawHeight = ItemTextSize.y;
        }
        MenuInterCalc(menu_buffer_item_scroll, menu_buffer_width_type, speed);
        MenuInterCalc(menu_buffer_item_scroll, menu_buffer_width_item, speed);
        ImGui::EndChild();

        return ReturnTypeFlag;
    }

    void SmoothMenuWindow::DrawMenuTypeRect(float rectHeight, const ImVec4 &color)
    {
        if (menu_buffer_width_type.y > 0.1f)
        {
            ListDrawRectangleFill(
                ImVec2(ItemCenteredCalc(menu_buffer_width_type.y), menu_buffer_type_scroll.y),
                ImVec2(menu_buffer_width_type.y, rectHeight + 2.0f), color);

            ImGui::SetCursorPos(ImVec2(0.0f, 0.0f));
        }
    }

    void SmoothMenuWindow::DrawMenuItemRect(float rectHeight, const ImVec4 &color)
    {
        ListDrawRectangleFill(
            ImVec2(ItemCenteredCalc(menu_buffer_width_item.y), menu_buffer_item_scroll.y),
            ImVec2(menu_buffer_width_item.y, rectHeight + 2.0f),
            color);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);
        ListDrawRectangleFill(
            ImVec2(ImGui::GetWindowSize().x - 12.0f, menu_buffer_item_scroll.y),
            ImVec2(IMGUI_ITEM_SPAC, rectHeight + 2.0f),
            color);

        ListDrawTriangleFill(
            ImVec2(IMGUI_ITEM_SPAC * 2.0f, menu_buffer_item_scroll.y + (rectHeight + 2.0f) * 0.5f),
            ImVec2(-rectHeight / 2.0f, -rectHeight / 2.0f),
            ImVec2(-rectHeight / 2.0f, rectHeight / 2.0f),
            color);
        ImGui::PopStyleVar();
        ImGui::SetCursorPos(ImVec2(0.0f, 0.0f));
    }

    void SmoothMenuWindow::MenuInterCalc(ImVec2 &posy_calc, ImVec2 &width_calc, float speed)
    {
        posy_calc.y += (posy_calc.x - posy_calc.y) * 0.072f * speed;
        width_calc.y += (width_calc.x - width_calc.y) * 0.072f * speed;
    }

    float ItemCenteredCalc(float width)
    {
        return ImGui::GetWindowSize().x / 2.0f - width / 2.0f;
    }

    void ListDrawRectangleFill(const ImVec2 &postion, const ImVec2 &size, const ImVec4 &color)
    {
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImGui::GetWindowPos() + postion,
            ImGui::GetWindowPos() + postion + size,
            IMVEC4_TO_COLU32(FLOAT_COLOR_CLAMP(color)),
            ImGui::GetStyle().FrameRounding,
            0);
    }

    void ListDrawTriangleFill(const ImVec2 &position, const ImVec2 &offset1, const ImVec2 &offset2, const ImVec4 &color)
    {
        // draw fill_triangle.
        ImGui::GetWindowDrawList()->AddTriangleFilled(
            ImGui::GetWindowPos() + position,
            ImGui::GetWindowPos() + position + offset1,
            ImGui::GetWindowPos() + position + offset2,
            IMVEC4_TO_COLU32(FLOAT_COLOR_CLAMP(color)));
    }
}