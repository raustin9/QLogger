#pragma once

/*
 * Mantis
 * common/defines.h
 *
 * Defines macros for platform detection and other things that are used
 * across the project
 *
 */

// Platform Detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define Q_PLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64 bit is required for windows"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
#define Q_PLATFORM_LINUX 1
#elif defined(__unix__)
#define Q_PLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
#define Q_PLATFORM_POSIX 1
#elif __APPLE__
#include <TargetConditionals.h>
#define Q_PLATFORM_APPLE 1
#endif

#ifdef QEXPORT
#ifdef _MSC_VER
#define QAPI __declspec(dllexport)
#else
#define QAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define QAPI __declspec(dllimport)
#else
#define QAPI
#endif
#endif
