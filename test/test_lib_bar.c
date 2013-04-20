#include <stdlib.h>

#include "test_lib_bar.h"

library_local int get_return_code(void)
{
	// This is the correct function function
	return 0;
}

api_export int test_lib_bar_global(void)
{
	return get_return_code();
}
