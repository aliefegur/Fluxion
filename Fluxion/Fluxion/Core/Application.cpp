
#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Fluxion
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        const WindowResizeEvent e(1920, 1080);
        FLX_TRACE(e.ToString());

        while (true);
    }
} // namespace Fluxion