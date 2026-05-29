#pragma once

#include "Fluxion/Core.h"

namespace Fluxion
{
    class FLX_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in client
    Application* CreateApplication();
} // namespace Fluxion
