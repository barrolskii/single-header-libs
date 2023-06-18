#include "test_dynamic_array.h"
#include "test_hashtable.h"

void setUp(void)
{
}

void tearDown(void)
{
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

	UNITY_BEGIN();

	run_dynamic_array_tests();
	run_hashtable_tests();

	return UNITY_END();
}
