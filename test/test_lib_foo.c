#include <stdlib.h>

#include "test_lib_foo.h"
#include "test_lib_bar.h"

api_export int test_lib_foo_global(void)
{
	return test_lib_bar_global();
}
