#pragma once
#ifndef __UTIL_EXPORT_H__
#define __UTIL_EXPORT_H__

#include "utilplatform.h"

/**
 * Export Macros
 * 
 * These macros controll the exporting of symbols. There are three main types of
 * export supported by them: global, global on debug and library-global. Any
 * functions that are part of an API should be marked `api_export`, functions
 * that should only be visible to other parts of the same library should be 
 * marked as `library_local_export` and functions that only need to be visible 
 * outiside this compilation unit to be accessed by unit tests should be marked
 * `debug_export`.
 * 
 * The export macros `api_export` and `library_local` are defined for each 
 * supported platform. The `debug_export` macro is conditionally defined to act
 * as a standard `api_export` if debugging is enabled and `static` othewise.
 */

#if defined(UTIL_PLATFORM_WINDOWS)
/* Windows, so use the windows import/export */
#  define library_local 
#  ifdef BUILDING_DLL
#    define api_export __declspec(dllexport)
#  else
#    define api_export __declspec(dllimport)
#  endif
#elif defined(UTIL_COMPILER_GCCLIKE)
/* clang or gcc or something like it, so use the attribute syntaxt */
#  define api_export    __attribute__((visibility("default")))
#  define library_local __attribute__((visibility("hidden")))
#else
/* unknown compiler. These definitions will work but will make some symbols more
 * visible than with a supported compiler. */
#  define api_export
#  define library_local
#endif

/* Define the `debug_export` macro */
#ifdef UTIL_DEBUG
#define debug_export  api_export
#else
#define debug_export  static
#endif

#endif
