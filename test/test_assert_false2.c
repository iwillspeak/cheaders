#include <stdlib.h>
#include <stdbool.h>

#include "../utilassert.h"

int main(int argc, char* argvp[])
{
	static_assert(false, this should fail);
	return 0;
}