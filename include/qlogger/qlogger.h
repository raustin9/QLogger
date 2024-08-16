/*
 * QLogger
 *
 * API Entrypoint for the logging utility
 */

#pragma once
#include <cstdio>
#include <string>
#include <fstream>
#include "platform/platform.h"

namespace qlogger {
constexpr int BUFSIZE = 200; // bytes to allocate on the stack for writing

class Logger {
public:
    Logger()
    : m_use_colors(true)
    , m_use_console(true)
    {}

    ~Logger() {
        m_log_file.close();
    }

    // Set the log file that we want to write the logs to
    bool set_log_file(const std::string& log_file_path) {
        m_log_file.open(log_file_path);

        if (!m_log_file.is_open()) {
            fatal("Unable to open log file: '%s'", log_file_path.c_str());
            return false;
        }

        return true;
    }

    // Whether we want to use colors or not.
    // NOTE: Colors will not be written to the log file regardless
    void use_colors(bool use_colors) {
        m_use_colors = use_colors;
    }

    // Whether we want to write to the console
    void use_console(bool use_console) {
        m_use_console = use_console;
    }


    template <typename ...Args>
    void fatal(const std::string& fmt, Args&&... args) {
        platform::color color = platform::color::RED;
        char buffer[BUFSIZE];
        std::string prefix = std::string("[FATAL] ") + fmt + '\n';
       
        snprintf(buffer, BUFSIZE, prefix.c_str(), args...);
       
        // If we have a log file open, write to that
        if (m_log_file.is_open()) {
            m_log_file << buffer;
        }

        if (m_use_console) {
            platform::console_error(color, buffer);
        }
    }

    template <typename ...Args>
    void error(const std::string& fmt, Args&&... args) {
        platform::color color = platform::color::ORANGE;
        char buffer[BUFSIZE];
        std::string prefix = std::string("[ERROR] ") + fmt + '\n';
       
        snprintf(buffer, BUFSIZE, prefix.c_str(), args...);
       
        // If we have a log file open, write to that
        if (m_log_file.is_open()) {
            m_log_file << buffer;
        }

        if (m_use_console) {
            platform::console_error(color, buffer);
        }
    }

    template <typename ...Args>
    void warn(const std::string& fmt, Args&&... args) {
        platform::color color = m_use_colors ? platform::color::YELLOW : platform::color::NONE;
        char buffer[BUFSIZE];
        std::string prefix = std::string("[WARN] ") + fmt + '\n';
       
        snprintf(buffer, BUFSIZE, prefix.c_str(), args...);
       
        // If we have a log file open, write to that
        if (m_log_file.is_open()) {
            m_log_file << buffer;
        }

        if (m_use_console) {
            platform::console_write(color, buffer);
        }
    }

    template <typename ...Args>
    void debug(const std::string& fmt, Args&&... args) {
        platform::color color = m_use_colors ? platform::color::MAGENTA : platform::color::NONE;
        char buffer[BUFSIZE];
        std::string prefix = std::string("[DEBUG] ") + fmt + '\n';
       
        snprintf(buffer, BUFSIZE, prefix.c_str(), args...);
       
        // If we have a log file open, write to that
        if (m_log_file.is_open()) {
            m_log_file << buffer;
        }

        if (m_use_console) {
            platform::console_write(color, buffer);
        }
    }

    template <typename ...Args>
    void info(const std::string& fmt, Args&&... args) {
        platform::color color = m_use_colors ? platform::color::CYAN : platform::color::NONE;
        char buffer[BUFSIZE];
        std::string prefix = std::string("[INFO] ") + fmt + '\n';
       
        snprintf(buffer, BUFSIZE, prefix.c_str(), args...);
       
        // If we have a log file open, write to that
        if (m_log_file.is_open()) {
            m_log_file << buffer;
        }

        if (m_use_console) {
            platform::console_write(color, buffer);
        }
    }

    template <typename ...Args>
    void trace(const std::string& fmt, Args&&... args) {
        platform::color color = m_use_colors ? platform::color::WHITE : platform::color::NONE;
        char buffer[BUFSIZE];
        std::string prefix = std::string("[TRACE] ") + fmt + '\n';
       
        snprintf(buffer, BUFSIZE, prefix.c_str(), args...);
       
        // If we have a log file open, write to that
        if (m_log_file.is_open()) {
            m_log_file << buffer;
        }

        if (m_use_console) {
            platform::console_write(color, buffer);
        }
    }
private:
    std::ofstream m_log_file; // the file stream for the output file
    bool m_use_colors;        // whether to use colors when logging
    bool m_use_console;       // whether to write to the console when logging
};

} // qlogger namespace
