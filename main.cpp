#include "App.h"
#include "ImList.h"
#include "common.h"
void App::Update()
{
    static std::vector<std::string> MenuListItem = {
        "通道1",
        "通道2",
        "通道3",
        "通道4",
        "通道2",
        "通道3通道",
        "通道4通道3",

    };

    static ImList::SmoothMenuWindow smoothMenu;
    static uint32_t count = 2;
    ImGui::SetNextWindowSize(ImVec2(256.0f, 386.0f));
    ImGui::Begin("main", nullptr, 0);
    smoothMenu.DrawMenuWindow("SmoothMenu", MenuListItem, count, HEX_TO_RGBA("#D8801B", 1.0f), ImVec2(-1, -1), 1.0f);
    ImGui::End();

    ImGui::SetNextWindowPos(ImGui::GetCursorScreenPos());
    ImGui::OpenPopup("DEBUG");
    if (ImGui::BeginTooltip())
    {
        ImGui::Text("scroll值：%f, %f", smoothMenu.menu_buffer_item_scroll.x, smoothMenu.menu_buffer_item_scroll.y);
        ImGui::Text("scroll值：%f, %f", smoothMenu.menu_buffer_width_item.x, smoothMenu.menu_buffer_width_item.y);
        ImGui::Text("scroll值：%f, %f", smoothMenu.menu_buffer_type_scroll.x, smoothMenu.menu_buffer_type_scroll.y);
        ImGui::Text("scroll值：%f, %f", smoothMenu.menu_buffer_width_type.x, smoothMenu.menu_buffer_width_type.y);
        ImGui::Text("count值为：%d", count);
        ImGui::EndTooltip();
    }
}

int main(int argc, char const *argv[])
{
    App app("ImDemo", 800, 600, argc, argv);
    app.Run();
    return 0;
}