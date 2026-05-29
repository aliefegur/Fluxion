#pragma once

#include "Application.h"

extern Fluxion::Application* Fluxion::CreateApplication();

int main(int argc, char** argv)
{
    const auto app = Fluxion::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
