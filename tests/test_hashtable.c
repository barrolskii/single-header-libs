#include "test_hashtable.h"

#define HASHTABLE_IMPLEMENTATION
#include "../hashtable/hashtable.h"

static void test_hashtable_add(void)
{
    hash_table_t *table = hash_table_init();

    int result = hash_table_add(table, "my_key", "my_value");

    TEST_ASSERT_EQUAL_INT(3, result);
    TEST_ASSERT_EQUAL_INT(1, table->count);

    hash_table_free(table);
}

static void test_hashtable_get(void)
{
    hash_table_t *table = hash_table_init();

    hash_table_add(table, "my_key", "my_value");
    char *value = hash_table_get(table, "my_key");

    TEST_ASSERT_EQUAL_STRING("my_value", value);

    hash_table_free(table);
}

static void test_hashtable_set(void)
{
    hash_table_t *table = hash_table_init();

    hash_table_add(table, "my_key", "my_value");
    char *value = hash_table_set(table, "my_key", "my_new_value");

    TEST_ASSERT_EQUAL_STRING("my_new_value", value);

    hash_table_free(table);
}

static void test_hashtable_remove(void)
{
    hash_table_t *table = hash_table_init();

    hash_table_add(table, "my_key", "my_value");
    hash_table_remove(table, "my_key");

    hash_item_t *item = hash_table_get(table, "my_key");

    TEST_ASSERT_EQUAL_PTR(NULL, item);
    TEST_ASSERT_EQUAL_INT(0, table->count);

    hash_table_free(table);
}

// TODO:??
/* static void test_hashtable_free_item(void) */
/* { */
/*     hash_table_t *table = hash_table_init(); */

/*     hash_table_free(table); */
/* } */

/* static void test_hashtable_clear_user_data(void) */
/* { */
/*     hash_table_t *table = hash_table_init(); */

/*     hash_table_free(table); */
/* } */

void run_hashtable_tests(void)
{
    RUN_TEST(test_hashtable_add);
    RUN_TEST(test_hashtable_get);
    RUN_TEST(test_hashtable_set);
    RUN_TEST(test_hashtable_remove);
    //RUN_TEST(test_hashtable_free_item);
    //RUN_TEST(test_hashtable_clear_user_data);
}
