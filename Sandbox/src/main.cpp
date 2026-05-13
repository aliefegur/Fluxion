#include <Fluxion/Core/Window/Window.h>

using namespace Fluxion;

int main(int argc, char** argv)
{
    WindowSpecification windowSpec;
    auto window = Window::Create(windowSpec);

    while (!window->ShouldClose())
    {
        window->Update();
    }
}
