#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/os.h>

namespace qlog
{
    class Logger
    {
    public:
        enum class LogLevel
        {
            FATAL = 0, CRITICAL, ERROR, WARN, INFO, DEBUG, TRACE
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

            m_LogFileName = "log.qlog";
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

        void SetFileLogging(bool logToFile)
        {
            m_LogToFile = logToFile;

            if (logToFile)
                ResetLogFile();
        }

        bool GetFileLogging()
        {
            return m_LogToFile;
        }

        // DONT USE FOR NOW
        void SetFileName(std::string_view filename)
        {
            m_LogFileName = filename;
        }

        std::string_view GetFileName()
        {
            return m_LogFileName;
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
            case LogLevel::CRITICAL:
                critical(str);
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
            std::string str = fmt::format("{0}[FATAL]: {1}\n", m_LogName, msg);
            fmt::print(fg(m_FatalFGColor) | bg(m_FatalBGColor), str);

            if (m_LogToFile)
            {
                fmt::ostream out = fmt::output_file(m_LogFileName, fmt::file::WRONLY | fmt::file::CREATE | fmt::file::APPEND);
                out.print("{}", str);
            }

            exit(0);
        }

        // critical is fatal without the crash - good for highlighting critical stuff
        void critical(std::string_view msg)
        {
            std::string str = fmt::format("{0}[CRITICAL]: {1}\n", m_LogName, msg);
            fmt::print(fg(m_FatalFGColor) | bg(m_FatalBGColor), str);

            if (m_LogToFile)
            {
                fmt::ostream out = fmt::output_file(m_LogFileName, fmt::file::WRONLY | fmt::file::CREATE | fmt::file::APPEND);
                out.print("{}", str);
            }
        }

        void error(std::string_view msg)
        {
            std::string str = fmt::format("{0}[ERROR]: {1}\n", m_LogName, msg);
            fmt::print(fg(m_ErrorFGColor), str);

            if (m_LogToFile)
            {
                fmt::ostream out = fmt::output_file(m_LogFileName, fmt::file::WRONLY | fmt::file::CREATE | fmt::file::APPEND);
                out.print("{}", str);
            }
        }

        void warn(std::string_view msg)
        {
            std::string str = fmt::format("{0}[WARN]: {1}\n", m_LogName, msg);
            fmt::print(fg(m_WarnFGColor), str);

            if (m_LogToFile)
            {
                fmt::ostream out = fmt::output_file(m_LogFileName, fmt::file::WRONLY | fmt::file::CREATE | fmt::file::APPEND);
                out.print("{}", str);
            }
        }

        void info(std::string_view msg)
        {
            std::string str = fmt::format("{0}[INFO]: {1}\n", m_LogName, msg);
            fmt::print(fg(m_InfoFGColor), str);

            if (m_LogToFile)
            {
                fmt::ostream out = fmt::output_file(m_LogFileName, fmt::file::WRONLY | fmt::file::CREATE | fmt::file::APPEND);
                out.print("{}", str);
            }
        }

        void debug(std::string_view msg)
        {
            std::string str = fmt::format("{0}[DEBUG]: {1}\n", m_LogName, msg);
            fmt::print(fg(m_DebugFGColor), str);

            if (m_LogToFile)
            {
                fmt::ostream out = fmt::output_file(m_LogFileName, fmt::file::WRONLY | fmt::file::CREATE | fmt::file::APPEND);
                out.print("{}", str);
            }
        }

        void trace(std::string_view msg)
        {
            std::string str = fmt::format("{0}[TRACE]: {1}\n", m_LogName, msg);
            fmt::print(fg(m_TraceFGColor), str);

            if (m_LogToFile)
            {
                fmt::ostream out = fmt::output_file(m_LogFileName, fmt::file::WRONLY | fmt::file::CREATE | fmt::file::APPEND);
                out.print("{}", str);
            }
        }
    private:
        void ResetLogFile()
        {
            fmt::ostream out = fmt::output_file(m_LogFileName);
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

        bool m_LogToFile = false;
        std::string m_LogFileName;
    };
}