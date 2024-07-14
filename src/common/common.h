#ifndef __COMMON__
#define __COMMON__
#include "imgui.h"
#include <string>
#define IMGUI_ITEM_SPAC ImGui::GetStyle().ItemSpacing.x

#define IMFXC_V_CLAMP(value, min, max) ((value) < (min) ? (min) : ((value) > (max) ? (max) : (value)))
#define IMFXC_PI 3.14159265f
#define IMFXC_DEGTORAD(deg) ((deg) * IMFXC_PI / 180.0f)

#define IMVEC2_DISTANCE(pos1, pos2) std::sqrt((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y))

#define IMFP32_TO_COLU32(R, G, B, A) IM_COL32(ImU32(R * 255.0f), ImU32(G * 255.0f), ImU32(B * 255.0f), ImU32(A * 255.0f))
#define COL_TO_FP32(V) ImU32((V) * 255.0f)
#define IMVEC4_TO_COLU32(COL) IM_COL32(COL_TO_FP32((COL).x), COL_TO_FP32((COL).y), COL_TO_FP32((COL).z), COL_TO_FP32((COL).w))

static inline ImVec2 operator+(const ImVec2 &v, const ImVec2 &s) { return ImVec2(v.x + s.x, v.y + s.y); }
static inline ImVec2 operator+(const ImVec2 &v, float s) { return ImVec2(v.x + s, v.y + s); }

static inline ImVec2 operator-(const ImVec2 &v, const ImVec2 &s) { return ImVec2(v.x - s.x, v.y - s.y); }
static inline ImVec2 operator-(const ImVec2 &v, float s) { return ImVec2(v.x - s, v.y - s); }
static inline ImVec2 operator-(float s, const ImVec2 &v) { return ImVec2(s - v.x, s - v.y); }

static inline ImVec2 operator*(const ImVec2 &v, const ImVec2 &s) { return ImVec2(v.x * s.x, v.y * s.y); }
static inline ImVec2 operator*(const ImVec2 &v, float s) { return ImVec2(v.x * s, v.y * s); }

static inline ImVec2 operator/(const ImVec2 &v, const ImVec2 &s) { return ImVec2(v.x / s.x, v.y / s.y); }
static inline ImVec2 operator/(const ImVec2 &v, float s) { return ImVec2(v.x / s, v.y / s); }
static inline ImVec2 operator/(float s, const ImVec2 &v) { return ImVec2(s / v.x, s / v.y); }

static inline ImVec2 &operator+=(ImVec2 &v1, const ImVec2 &v2) { return v1 = v1 + v2; }
static inline ImVec2 &operator-=(ImVec2 &v1, const ImVec2 &v2) { return v1 = v1 - v2; }
static inline ImVec2 &operator*=(ImVec2 &v1, const ImVec2 &v2) { return v1 = v1 * v2; }
static inline ImVec2 &operator/=(ImVec2 &v1, const ImVec2 &v2) { return v1 = v1 / v2; }

static inline ImVec4 operator+(const ImVec4 &v, const ImVec4 &s) { return ImVec4(v.x + s.x, v.y + s.y, v.z + s.z, v.w + s.w); }
static inline ImVec4 operator+(const ImVec4 &v, float s) { return ImVec4(v.x + s, v.y + s, v.z + s, v.w + s); }

static inline ImVec4 operator-(const ImVec4 &v, const ImVec4 &s) { return ImVec4(v.x - s.x, v.y - s.y, v.z - s.z, v.w - s.w); }
static inline ImVec4 operator-(const ImVec4 &v, float s) { return ImVec4(v.x - s, v.y - s, v.z - s, v.w - s); }
static inline ImVec4 operator-(float s, const ImVec4 &v) { return ImVec4(s - v.x, s - v.y, s - v.z, s - v.w); }

static inline ImVec4 operator*(const ImVec4 &v, const ImVec4 &s) { return ImVec4(v.x * s.x, v.y * s.y, v.z * s.z, v.w * s.w); }
static inline ImVec4 operator*(const ImVec4 &v, float s) { return ImVec4(v.x * s, v.y * s, v.z * s, v.w * s); }

static inline ImVec4 operator/(const ImVec4 &v, const ImVec4 &s) { return ImVec4(v.x / s.x, v.y / s.y, v.z / s.z, v.w / s.w); }
static inline ImVec4 operator/(const ImVec4 &v, float s) { return ImVec4(v.x / s, v.y / s, v.z / s, v.w / s); }
static inline ImVec4 operator/(float s, const ImVec4 &v) { return ImVec4(s / v.x, s / v.y, s / v.z, s / v.w); }

static inline ImVec4 &operator+=(ImVec4 &v1, const ImVec4 &v2) { return v1 = v1 + v2; }
static inline ImVec4 &operator-=(ImVec4 &v1, const ImVec4 &v2) { return v1 = v1 - v2; }
static inline ImVec4 &operator*=(ImVec4 &v1, const ImVec4 &v2) { return v1 = v1 * v2; }
static inline ImVec4 &operator/=(ImVec4 &v1, const ImVec4 &v2) { return v1 = v1 / v2; }

static inline ImVec4 FLOAT_COLOR_CLAMP(const ImVec4 &color)
{
    return ImVec4(
        IMFXC_V_CLAMP(color.x, 0.0f, 1.0f), IMFXC_V_CLAMP(color.y, 0.0f, 1.0f),
        IMFXC_V_CLAMP(color.z, 0.0f, 1.0f), IMFXC_V_CLAMP(color.w, 0.0f, 1.0f));
}

static inline ImVec4 HEX_TO_RGBA(const std::string &hexColor, float alpha)
{
    ImVec4 rgbaColor;
    std::string hex = hexColor;
    if (hex[0] == '#')
        hex.erase(0, 1);

    int color = std::stoi(hex, NULL, 16);
    int red = color >> 16 & 0xFF;
    int green = color >> 8 & 0xFF;
    int blue = color & 0xFF;

    rgbaColor.x = red / 255.0f;
    rgbaColor.y = green / 255.0f;
    rgbaColor.z = blue / 255.0f;
    rgbaColor.w = alpha;

    return rgbaColor;
}

#define IMCB_SCALE_CALC(high, value) high - value < 0.0f ? 0.0f : high - value &&high - value > 1.0f ? 1.0f \
                                                                                                     : high - value
static inline ImVec4 ColorBrightnesScale(const ImVec4 &color, float value)
{
    return ImVec4(
        IMCB_SCALE_CALC(color.x, value), IMCB_SCALE_CALC(color.y, value), // red,green
        IMCB_SCALE_CALC(color.z, value), IMCB_SCALE_CALC(color.w, value)  // blue,alpha
    );
}
#endif
