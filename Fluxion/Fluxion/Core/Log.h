#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace Fluxion
{
    class Log
    {
    public:
        static void Initialize();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger()
        {
            return s_CoreLogger;
        }
        static std::shared_ptr<spdlog::logger>& GetClientLogger()
        {
            return s_ClientLogger;
        }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
} // namespace Fluxion

#define FLX_CORE_ERROR(...) ::Fluxion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FLX_CORE_WARN(...) ::Fluxion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FLX_CORE_INFO(...) ::Fluxion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FLX_CORE_TRACE(...) ::Fluxion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FLX_CORE_FATAL(...) ::Fluxion::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define FLX_ERROR(...) ::Fluxion::Log::GetClientLogger()->error(__VA_ARGS__)
#define FLX_WARN(...) ::Fluxion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FLX_INFO(...) ::Fluxion::Log::GetClientLogger()->info(__VA_ARGS__)
#define FLX_TRACE(...) ::Fluxion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FLX_FATAL(...) ::Fluxion::Log::GetClientLogger()->fatal(__VA_ARGS__)
