#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>

namespace qlog
{
    class Logger
    {
    public:
        enum class LogLevel
        {
            FATAL = 0, ERROR, WARN, INFO, DEBUG, TRACE
        };

        void Init()
        {
            // Set the default log message colors
            m_FatalFGColor = fmt::color::white;
            m_ErrorFGColor = fmt::color::red;
            m_WarnFGColor = fmt::color::yellow;
            m_InfoFGColor = fmt::color::white;
            m_DebugFGColor = fmt::color::forest_green;
            m_TraceFGColor = fmt::color::blue;

            // Set the background colors
            m_FatalBGColor = fmt::color::crimson;

            // Control defaults
            m_LogName = "[qlog]";
        }

        // Control getters/setters
        void SetName(std::string_view name)
        {
            m_LogName = "[";
            m_LogName.append(name.data());
            m_LogName.append("]");
        }

        std::string_view GetName()
        {
            return m_LogName;
        }

        template <typename... T>
        void Log(LogLevel lvl, fmt::format_string<T...> fmt, T&&... args)
        {
            std::string str = fmt::format(fmt, std::forward<T>(args)...);
            switch (lvl)
            {
            case LogLevel::FATAL:
                fatal(str);
                break;
            case LogLevel::ERROR:
                error(str);
                break;
            case LogLevel::WARN:
                warn(str);
                break;
            case LogLevel::INFO:
                info(str);
                break;
            case LogLevel::DEBUG:
                debug(str);
                break;
            case LogLevel::TRACE:
                trace(str);
                break;
            }
        }

        // Might make private later
        // Log level specific printing functions
        void fatal(std::string_view msg)
        {
            fmt::print(fg(m_FatalFGColor) | bg(m_FatalBGColor), "{0}[FATAL]: {1}\n", m_LogName, msg);
            //exit(0);
        }

        void error(std::string_view msg)
        {
            fmt::print(fg(m_ErrorFGColor), "{0}[ERROR]: {1}\n", m_LogName, msg);
        }

        void warn(std::string_view msg)
        {
            fmt::print(fg(m_WarnFGColor), "{0}[WARN]: {1}\n", m_LogName, msg);
        }

        void info(std::string_view msg)
        {
            fmt::print(fg(m_InfoFGColor), "{0}[INFO]: {1}\n", m_LogName, msg);
        }

        void debug(std::string_view msg)
        {
            fmt::print(fg(m_DebugFGColor), "{0}[DEBUG]: {1}\n", m_LogName, msg);
        }

        void trace(std::string_view msg)
        {
            fmt::print(fg(m_TraceFGColor), "{0}[TRACE]: {1}\n", m_LogName, msg);
        }
    private:
        // Log level text (foreground) colors
        fmt::color m_FatalFGColor;
        fmt::color m_ErrorFGColor;
        fmt::color m_WarnFGColor;
        fmt::color m_InfoFGColor;
        fmt::color m_DebugFGColor;
        fmt::color m_TraceFGColor;

        // Log level background colors
        fmt::color m_FatalBGColor;

        // Controls
        std::string m_LogName;

    };
}