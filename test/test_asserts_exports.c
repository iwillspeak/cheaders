#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "../utilassert.h"
#include "../utilexport.h"
#include "../utilplatform.h"

debug_export void foo(void)
{
	// DOn't do anything
}

library_local int32_t bar(void)
{
	foo();

	return 1234;
}

api_export int main(int argc, char* argv[])
{
	static_assert(true, "True should be true");
	static_assert_false(false, false should be false);
	static_assert(
		sizeof(uint64_t) == 8, "64 bit integer should be 8 bytes long");
}