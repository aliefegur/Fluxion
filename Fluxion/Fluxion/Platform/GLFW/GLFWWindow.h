#include "Fluxion/Core/Window/Window.h"
#include "Fluxion/Core/Window/WindowSpecification.h"

struct GLFWwindow;

namespace Fluxion
{
    class GLFWWindow : public Window
    {
    public:
        GLFWWindow(const WindowSpecification& specs);
        GLFWWindow(const GLFWWindow&)            = delete;
        GLFWWindow& operator=(const GLFWWindow&) = delete;
        GLFWWindow(const GLFWWindow&&)           = delete;
        Window& operator=(const GLFWWindow&&)    = delete;
        ~GLFWWindow() override;

        void               Update() override;
        [[nodiscard]] bool ShouldClose() const override;
        [[nodiscard]] int  GetWidth() const override;
        [[nodiscard]] int  GetHeight() const override;

    private:
        GLFWwindow* m_Window;
        int         m_Width, m_Height;
    };
} // namespace Fluxion
