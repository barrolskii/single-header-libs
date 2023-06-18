#include "test_dynamic_array.h"

#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "../dynamic-array/dynamic_array.h"

static void test_dynamic_array_set_size(void)
{
    dynamic_array *array = dynamic_array_init();

    dynamic_array_set_size(array, 20);
    TEST_ASSERT_EQUAL_INT(20, array->size);

    dynamic_array_free(array);
}

static void test_dynamic_array_add(void)
{
    dynamic_array *array = dynamic_array_init();

    int a = 2, b = 3;

    dynamic_array_add(array, &a);
    dynamic_array_add(array, &b);

    TEST_ASSERT_EQUAL_INT(2, array->size);
    TEST_ASSERT_EQUAL_INT(8, array->capacity);

    dynamic_array_free(array);
}

static void test_dynamic_array_clear(void)
{
    dynamic_array *array = dynamic_array_init();

    int a = 2, b = 3;

    dynamic_array_add(array, &a);
    dynamic_array_add(array, &b);
    dynamic_array_clear(array);

    TEST_ASSERT_EQUAL_INT(0, array->size);
    TEST_ASSERT_EQUAL_INT(8, array->capacity);

    dynamic_array_free(array);
}

static void populate_array(dynamic_array *array, unsigned n_elem)
{
    for (unsigned i = 0; i < n_elem; ++i)
    {
        unsigned *data = malloc(sizeof(int));
        *data = i;

        dynamic_array_add(array, data);
    }
}

static void test_dynamic_array_clear_user_data(void)
{
    dynamic_array *array = dynamic_array_init();

    populate_array(array, 5);
    dynamic_array_clear_user_data(array, free);

    TEST_ASSERT_EQUAL_INT(0, array->size);
    TEST_ASSERT_EQUAL_INT(12, array->capacity);

    dynamic_array_free(array);
}

static void test_dynamic_array_insert(void)
{
    dynamic_array *array = dynamic_array_init();
    int result_one, result_two;
    int a = 1, b = 2;

    dynamic_array_set_size(array, 20);
    result_one = dynamic_array_insert(array, 10, &a);
    result_two = dynamic_array_insert(array, 21, &b);

    TEST_ASSERT_EQUAL_INT(0, result_one);
    TEST_ASSERT_EQUAL_INT(-1, result_two);

    dynamic_array_free(array);
}

void run_dynamic_array_tests(void)
{
    RUN_TEST(test_dynamic_array_set_size);
    RUN_TEST(test_dynamic_array_add);
    RUN_TEST(test_dynamic_array_clear);
    RUN_TEST(test_dynamic_array_clear_user_data);
    RUN_TEST(test_dynamic_array_insert);
}
