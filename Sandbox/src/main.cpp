#include <Fluxion/Fluxion.h>

class Sandbox : public Fluxion::Application
{
public:
    Sandbox()
    {
        FLX_LOG_INFO("Hello World!");
    }

    ~Sandbox() override
    {
        FLX_LOG_WARN("Goodbye World!");
    }
};

Fluxion::Application* Fluxion::CreateApplication()
{
    return new Sandbox();
}
