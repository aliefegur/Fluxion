#pragma once

#include "Application.h"

extern Fluxion::Application* Fluxion::CreateApplication();

int main(int argc, char** argv)
{
    // Initialize logging system
    Fluxion::Log::Initialize();

    // Create, run & delete application
    const auto app = Fluxion::CreateApplication();
    app->Run();
    delete app;

    // Close program
    return 0;
}
