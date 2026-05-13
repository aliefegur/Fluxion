#include "Window.h"

#include "GLFWWindow.h"

namespace Fluxion
{
    std::unique_ptr<Window> Window::Create(const WindowSpecification& spec)
    {
        return std::make_unique<GLFWWindow>(spec);
    }
} // namespace Fluxion
