#pragma once
#ifndef __UTIL_PLATFORM_H__
#define __UTIL_PLATFORM_H__

/**
 * Platform Constants
 */
#define UTIL_PLATFORM_UNKNOWN 0
#define UTIL_PLATFORM_DARWIN  1
#define UTIL_PLATFORM_LINUX   2
#define UTIL_PLATFORM_WINDOWS 3

/**
 * Compiler Constants
 */
#define UTIL_COMPILER_CLANG   1
#define UTIL_COMPILER_GCC     2
#define UTIL_COMPILER_MSVCC   3


/* we are running on Mac, bear with me for now.. :-p */
#define UTIL_COMPILER UTIL_COMPILER_CLANG
#define UTIL_PLATFORM UTIL_PLATFORM_DARWIN

#endif
