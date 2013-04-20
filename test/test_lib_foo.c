#include <stdlib.h>

#include "test_lib_foo.h"
#include "test_lib_bar.h"

library_local int get_return_code(void)
{
	// This is the wrong function
	return 1;
}

api_export int test_lib_foo_global(void)
{
	return test_lib_bar_global();
}
