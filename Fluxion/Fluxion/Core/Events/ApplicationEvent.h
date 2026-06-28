#pragma once

#include "Event.h"

#include <cstdint>
#include <sstream>

namespace Fluxion
{
    class FLX_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(uint32_t w, uint32_t h) : m_Width(w), m_Height(h) {}

        unsigned int GetWidth() const
        {
            return m_Width;
        }
        unsigned int GetHeight() const
        {
            return m_Height;
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        uint32_t m_Width, m_Height;
    };

    class FLX_API WindowCloseEvent : public Event
    {
    public:
        
    };
} // namespace Fluxion
