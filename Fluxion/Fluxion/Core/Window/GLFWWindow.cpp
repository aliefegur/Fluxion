#include "GLFWWindow.h"

// NOTE: This is Linux version, it will be changed when Windows support needed!
#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3native.h>

#include <iostream>

namespace Fluxion
{
    static bool   s_GLFWInitialized = false;
    static size_t s_GLFWWindowCount = 0;

    GLFWWindow::GLFWWindow(const WindowSpecification& windowSpec)
    {
        // Initialize GLFW if it is not initialized
        if (!s_GLFWInitialized)
        {
            if (glfwInit() == GLFW_FALSE)
            {
                std::cerr << "[ENGINE::CORE] Failed to Initialize GLFW!" << std::endl;
                return;
            }
        }

        // Create window
        m_Window = glfwCreateWindow(windowSpec.Width, windowSpec.Height, windowSpec.Title.c_str(), nullptr, nullptr);

        // Check errors
        if (m_Window == nullptr)
        {
            std::cerr << "[ENGINE::CORE] Failed Create GLFW Window!" << std::endl;
            return;
        }

        ++s_GLFWWindowCount;
    }

    GLFWWindow::~GLFWWindow()
    {
        // Destroy window if exists
        if (m_Window != nullptr)
        {
            glfwDestroyWindow(m_Window);
        }

        // Terminate GLFW if there is no active window
        if (--s_GLFWWindowCount == 0)
        {
            glfwTerminate();
            s_GLFWInitialized = false;
        }
    }

    void GLFWWindow::Update()
    {
        glfwPollEvents();
        glfwGetWindowSize(m_Window, &m_Width, &m_Height);
    }

    bool GLFWWindow::ShouldClose() const
    {
        return glfwWindowShouldClose(m_Window);
    }

    int GLFWWindow::GetWidth() const
    {
        return m_Width;
    }

    int GLFWWindow::GetHeight() const
    {
        return m_Height;
    }
} // namespace Fluxion