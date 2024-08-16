/*
 * QLogger
 * platform/platform.h
 * 
 * The interface for writing to different platforms.
 * The implementations of these will differ platform to platform,
 * but can be used agnostically of platform.
 *
 */

#pragma once
#include <string>
#include "defines.h"

namespace qlogger {

namespace platform {

// The list of colors that are able to be printed to the console
enum class color : int {
    RED,
    MAGENTA,
    BLUE,
    CYAN,
    WHITE,
    BLACK,
    YELLOW,
    GREEN,
    NONE,

    NUM_COLORS
};

void console_write(color msg_color, const std::string& msg);

void console_error(color msg_color, const std::string& err);

} // platform namespace

} // qlogger namespace
