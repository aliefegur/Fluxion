#include <Fluxion/Core/Window/Window.h>

using namespace Fluxion;

int main(int argc, char** argv)
{
    constexpr int WIDTH = 1280;
    constexpr int HEIGHT = 720;

    WindowSpecification windowSpec;
    windowSpec.Width = WIDTH;
    windowSpec.Height = HEIGHT;
    auto window = Window::Create(windowSpec);

    while (!window->ShouldClose())
    {
        window->Update();
    }
}
