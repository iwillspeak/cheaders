#pragma once
#ifndef __UTIL_ASSERT_H__
#define __UTIL_ASSERT_H__

/*
 * Static Assertion Macro
 * 
 * Use this macro to check that a given predicate holds true at compilation
 * time. This can be used to check things such as the size of structures 
 * or alignment of structure contents.
 */
#define static_assert(tst, msg) _Static_assert((tst), #msg)

/**
 * Static Assert False
 * 
 * Assert that a predicate _does not_ hold at compilation time.
 */
#define static_assert_false(tst, msg)   static_assert(!(tst), msg)

#endif
