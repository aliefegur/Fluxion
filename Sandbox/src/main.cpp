#include <Fluxion/Core/Window/Window.h>
#include <Fluxion/Core/Log.h>

using namespace Fluxion;

int main(int argc, char** argv)
{
    Log::Initialize();
    FLX_CORE_WARN("Logging system initialized!");
    int a = 6;
    FLX_LOG_INFO("Hello! a={0}", a);

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
