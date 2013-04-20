#include "../utilassert.h"

#include "../utilplatform.h"
#ifdef UTIL_DEBUG
static_assert(false, debug should not be defined);
#endif

int main(int argc, char* argv[])
{
	return 0;
}