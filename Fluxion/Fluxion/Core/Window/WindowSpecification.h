#pragma once

#include <string>

namespace Fluxion
{
    struct WindowSpecification
    {
        std::string Title = "Fluxion Window";

        int Width = 1280;
        int Height = 720;

        bool VSync = true;
        bool Resizable = true;
        bool Maximized = false;
        bool Decorated = true;
    };
}
