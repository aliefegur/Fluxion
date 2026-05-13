#pragma once

#include "WindowSpecification.h"

#include <memory>

namespace Fluxion
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void Update()            = 0;
        virtual bool ShouldClose() const = 0;

        virtual int GetWidth() const  = 0;
        virtual int GetHeight() const = 0;

        static std::unique_ptr<Window> Create(const WindowSpecification& windowSpec);
    };
} // namespace Fluxion
