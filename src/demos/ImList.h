
#ifndef __IMLIST__
#define __IMLIST__

#include "imgui.h"
#include "vector"
#include "string"
#include "stdint.h"
namespace ImList
{

    class SmoothMenuWindow
    {
    public:
        ImVec2 menu_buffer_type_scroll = {};
        ImVec2 menu_buffer_width_type = {};

        ImVec2 menu_buffer_item_scroll = {};
        ImVec2 menu_buffer_width_item = {};

        float TextDrawHeight = 0.0f;
        void DrawMenuTypeRect(float rectHeight, const ImVec4 &color);
        void DrawMenuItemRect(float rectHeight, const ImVec4 &color);
        void MenuInterCalc(ImVec2 &posyCalc, ImVec2 &widthCalc, float speed);
        bool DrawMenuWindow(
            const char *name,
            const std::vector<std::string> &items,
            uint32_t &count,
            const ImVec4 &color = ImVec4(0.0f, 0.92f, 0.86f, 0.78f),
            const ImVec2 &size = ImVec2(256.0f, 384.0f),
            float speed = 1.0f,
            float text_scale = 1.2f

        );
    };

    float ItemCenteredCalc(float width);
    void ListDrawRectangleFill(const ImVec2 &postion, const ImVec2 &size, const ImVec4 &color);
    void ListDrawTriangleFill(const ImVec2 &position, const ImVec2 &offset1, const ImVec2 &offset2, const ImVec4 &color);
}
#endif
