#ifndef __APP__
#define __APP__
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>

#if defined(_WIN32) && defined(APP_NO_CONSOLE)
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

class App
{
public:
    App(std::string title, int w, int h, int argc, char const *argv[]);
    virtual ~App();
    virtual void Start() {};
    virtual void Update();
    void Run();
    ImVec2 GetWindowSize() const;

    ImVec4 ClearColor;
    GLFWwindow *Window;
    bool UsingGPU;
};
#endif