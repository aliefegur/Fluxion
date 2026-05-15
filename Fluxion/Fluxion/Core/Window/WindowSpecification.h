#pragma once

#include <string>

namespace Fluxion
{
    struct WindowSpecification
    {
        std::string Title = "Fluxion Engine";
        int         Width;
        int         Height;
        bool        VSync      = true;
        bool        FullScreen = false;
        bool        Resizable  = true;
        bool        Maximized  = false;
        bool        Decorated  = true;
    };
} // namespace Fluxion
