#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace Fluxion
{

    class GLFWWindow : public Window
    {
    public:
        GLFWWindow(const WindowSpecification& windowSpec);
        ~GLFWWindow() override;

        void Update() override;
        bool ShouldClose() const override;

        int GetWidth() const override;
        int GetHeight() const override;

    private:
        GLFWwindow* m_Window = nullptr;
        int m_Width = 0;
        int m_Height = 0;
    };

} // namespace Fluxion
