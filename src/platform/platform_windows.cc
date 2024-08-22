/*
 * QLogger
 * platform/platform_linux.cc
 *
 * The 
 *
 */

#include "platform/platform.h"
#include "platform/defines.h"
#include "qlogger.h"
#include <windows.h>

#ifdef Q_PLATFORM_WINDOWS
namespace qlogger {

namespace platform {

constexpr int COLOR_BLACK = 0;
constexpr int COLOR_BLUE = 1;
constexpr int COLOR_GREEN = 2;
constexpr int COLOR_AQUA = 3;
constexpr int COLOR_RED = 4;
constexpr int COLOR_PURPLE = 5;
constexpr int COLOR_YELLOW = 6;
constexpr int COLOR_WHITE = 7;
constexpr int COLOR_GRAY = 8;
constexpr int COLOR_LIGHT_BLUE = 9;
constexpr int COLOR_LIGHT_GREEN = 10;
constexpr int COLOR_LIGHT_AQUA = 11;
constexpr int COLOR_LIGHT_RED = 12;
constexpr int COLOR_LIGHT_PURPLE = 13;
constexpr int COLOR_LIGHT_YELLOW = 14;
constexpr int COLOR_BRIGHT_WHITE = 15;

constexpr int color_to_value(color c) {
    switch (c) {
        case color::RED:
            return COLOR_RED;
        case color::BLUE:
            return COLOR_BLUE;
        case color::MAGENTA:
            return COLOR_LIGHT_PURPLE;
        case color::CYAN:
            return COLOR_LIGHT_AQUA;
        case color::WHITE:
            return COLOR_BRIGHT_WHITE;
        case color::YELLOW:
            return COLOR_YELLOW;
        case color::GREEN:
            return COLOR_GREEN;
        
        case color::NONE:
        default:
            return 7;
    }
}

void console_write(color msg_color, const std::string& msg) {
    CONSOLE_SCREEN_BUFFER_INFO Info;
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console_handle, &Info);
	WORD Attributes = Info.wAttributes;

	SetConsoleTextAttribute(console_handle, color_to_value(msg_color));

	OutputDebugStringA(msg.c_str());
	uint64_t length = msg.length();
	LPDWORD number_written = 0;
	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), msg.c_str(), (DWORD)length, number_written, 0);
	SetConsoleTextAttribute(console_handle, Attributes);
}

void console_error(color msg_color, const std::string& msg) {
    CONSOLE_SCREEN_BUFFER_INFO Info;
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console_handle, &Info);
	WORD Attributes = Info.wAttributes;

	SetConsoleTextAttribute(console_handle, color_to_value(msg_color));

	OutputDebugStringA(msg.c_str());
	uint64_t length = msg.length();
	LPDWORD number_written = 0;
	WriteConsoleA(GetStdHandle(STD_ERROR_HANDLE), msg.c_str(), (DWORD)length, number_written, 0);
	SetConsoleTextAttribute(console_handle, Attributes);
}

}

} // qlogger namespace
#endif // Q_PLATFORM_WINDOWS