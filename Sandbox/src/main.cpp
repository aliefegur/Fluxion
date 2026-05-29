#include <Fluxion/Fluxion.h>

class Sandbox : public Fluxion::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox() override
    {

    }
};

Fluxion::Application* Fluxion::CreateApplication()
{
    return new Sandbox();
}
