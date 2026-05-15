#include "Window.h"

#include "Fluxion/Core/Window/WindowSpecification.h"
#include "Fluxion/Platform/GLFW/GLFWWindow.h"

#include <memory>

namespace Fluxion
{
    Window::Window(const WindowSpecification& specs) {}

    std::unique_ptr<Window> Window::Create(const WindowSpecification& specs)
    {
        return std::make_unique<GLFWWindow>(specs);
    }
} // namespace Fluxion
