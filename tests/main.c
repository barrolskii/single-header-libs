#include "test_dynamic_array.h"
#include "test_hashtable.h"

int main(int argc, char **argv)
{
	UNITY_BEGIN();

	run_dynamic_array_tests();
	run_hashtable_tests();

	return UNITY_END();
}
