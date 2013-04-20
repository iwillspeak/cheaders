#pragma once
#ifndef __UTIL_PLATFORM_H__
#define __UTIL_PLATFORM_H__

/**
 * Define UTIL_PLATFORM constant
 *
 * UTIL_PLATFORM_UNIXLIKE
 *   UTIL_PLATFORM_DARWIN
 *   UTIL_PLATFORM_LINUX
 *   UTIL_PLATFORM_BSD
 * UTIL_PLATFORM_WINDOWS
 * UTIL_PLATFORM_UNKNOWN
 */
#if defined(__APPLE__) && defined(__MACH__)
#  define UTIL_PLATFORM_DARWIN
#elif defined(__gnu_linux__)
#  define UTIL_PLATFORM_LINUX
#elif defined(__FreeBSD__) ||  defined(__NetBSD__) ||  defined(__OpenBSD__) ||  defined(__bsdi__) ||  defined(__DragonFly__)
#  define UTIL_PLATFORM_BSD
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#  define UTIL_PLATFORM_WINDOWS
#else
#  warning "util: Unknown platform"
#  define UTIL_PLATFORM_UNKNOWN
#endif

#if defined(UTIL_PLATFORM_LINUX) || defined(UTIL_PLATFORM_DARWIN) || defined(UTIL_PLATFORM_BSD)
#  define UTIL_PLATFORM_UNIXLIKE
#endif

/**
 * Define UTIL_COMPILER constant
 *
 * UTIL_COMPILER_GCCLIKE
 *   UTIL_COMPILER_CLANG
 *   UTIL_COMPILER_GCC
 * UTIL_COMPILER_MSVCC
 * UTIL_COMPILER_UNKNOWN
 */
#if defined(__clang__)
#  define UTIL_COMPILER_CLANG
#elif defined(__GNUC__)
#  define UTIL_COMPILER_GCC
#elif defined(_MSC_VER)
#  define UTIL_COMPILER_MSVCC
#else
#  warning "util: Unknown compiler"
#  define UTIL_COMPILER_UNKNOWN
#endif

#if defined(UTIL_COMPILER_CLANG) || defined(UTIL_COMPILER_GCC)
#  define UTIL_COMPILER_GCCLIKE
#endif

#endif
