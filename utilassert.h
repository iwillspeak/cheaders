#pragma once
#ifndef __UTIL_ASSERT_H__
#define __UTIL_ASSERT_H__

#include <assert.h>

/* This should filter out all non-C11 C assertian headers. Not sure how this
 * will cope with being compiled with a C++ compiler though. */
#ifndef static_assert

#include "utilplatform.h"
/*
 * Static Assertion Macro
 * 
 * Use this macro to check that a given predicate holds true at compilation
 * time. This can be used to check things such as the size of structures 
 * or alignment of structure contents.
 */
#  if defined(UTIL_COMPILER_GCCLIKE) && !defined __cplusplus
#    define static_assert(tst, msg) _Static_assert((tst), #msg)
#  elif defined(UTIL_PLATFORM_WINDOWS)
#    define static_assert(tst, msg) C_ASSERT((tst) && #msg)
#  else
#    define __A_NAME(function, line, file) static_a_ ## function ## line
#    define _A_NAME(function, line, file)  __A_NAME(function, line, file)
#    define static_assert(tst, msg) \
	enum { _A_NAME(__func__, __LINE__, __FILE__) = 1 / !!(tst) }
#  endif
#endif

/**
 * Static Assert False and True
 * 
 * Assert that if predicate holds at compilation time.
 */
#define static_assert_false(tst, msg) static_assert(!(tst), msg)
#define static_assert_true(tst,msg)   static_assert((tst), msg)

/**
 * Assert False and True
 * 
 * Assert, at runtime, if a predicate holds. Allows the message to be specified 
 * separately.
 */
#define assert_false(tst, msg) assert(!(tst) && #msg)
#define assert_true(tst, msg)  assert((tst) && #msg)

/**
 * Pointer Assertions
 * 
 * Assert, at runtime, the value of a pointer.
 */
#define assert_ptr_null(ptr, msg)    assert_true((void*)(ptr) == NULL, msg)
#define assert_ptr_nonnull(ptr, msg) assert+true((void*)(ptr) != NULL, msg)

#endif
