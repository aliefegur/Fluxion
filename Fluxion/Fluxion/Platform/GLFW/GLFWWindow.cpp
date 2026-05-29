#include "GLFWWindow.h"

#include "Fluxion/Core/Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Fluxion
{
    static bool          s_GlfwInitialized    = false;
    static int           s_ActiveWindowCount  = 0;
    static constexpr int OPENGL_VERSION_MAJOR = 4;
    static constexpr int OPENGL_VERSION_MINOR = 6;

    GLFWWindow::GLFWWindow(const WindowSpecification& specs) : Window(specs)
    {
        if (!s_GlfwInitialized)
        {
            if (glfwInit() == GLFW_FALSE)
            {
                FLX_CORE_ERROR("Failed to initialize GLFW!");
                return;
            }

            s_GlfwInitialized = true;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);

        m_Window = glfwCreateWindow(specs.Width, specs.Height, specs.Title.c_str(), nullptr, nullptr);
        if (m_Window == nullptr)
        {
            FLX_CORE_ERROR("Failed to create GLFW Window!");
            return;
        }

        if (specs.VSync)
        {
            glfwSwapInterval(1);
        }

        // Create context
        glfwMakeContextCurrent(m_Window);
        if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == GL_FALSE)
        {
            FLX_CORE_ERROR("Failed to initialize OpenGL Context!");
        }

        m_Width  = specs.Width;
        m_Height = specs.Height;

        ++s_ActiveWindowCount;
    }

    GLFWWindow::~GLFWWindow()
    {
        glfwDestroyWindow(m_Window);

        if (--s_ActiveWindowCount == 0)
        {
            glfwTerminate();
            s_GlfwInitialized = false;
        }
    }

    void GLFWWindow::Update()
    {
        glfwSwapBuffers(m_Window); // TODO: Swap buffers maybe moved to the Context class
        glfwPollEvents();
        glfwGetWindowSize(m_Window, &m_Width, &m_Height);
    }

    bool GLFWWindow::ShouldClose() const
    {
        return glfwWindowShouldClose(m_Window) == GLFW_TRUE;
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
