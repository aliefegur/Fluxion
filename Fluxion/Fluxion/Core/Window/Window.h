#pragma once

#include "Fluxion/Core/Window/WindowSpecification.h"

#include <memory>

namespace Fluxion
{
    class Window
    {
        friend class Context;

    public:
        Window(const WindowSpecification& specs);
        Window(const Window&)             = delete;
        Window& operator=(const Window&)  = delete;
        Window(const Window&&)            = delete;
        Window& operator=(const Window&&) = delete;
        virtual ~Window()                 = default;

        virtual void               Update()            = 0;
        [[nodiscard]] virtual bool ShouldClose() const = 0;
        [[nodiscard]] virtual int  GetWidth() const    = 0;
        [[nodiscard]] virtual int  GetHeight() const   = 0;

        static std::unique_ptr<Window> Create(const WindowSpecification& specs);
    };
} // namespace Fluxion
