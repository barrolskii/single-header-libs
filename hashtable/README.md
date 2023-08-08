# hashtable

Hashtable implementation for C using a dynamically resizing, open addressed hashtable.

## Quick Start

Copy hashtable.h into your project and include it like this:

``` c
#define HASH_TABLE_IMPLEMENTATION
#include "hashtable.h"
```
 
This is a stb style header only library. For more information about stb style
headers libraries see [stb_howto.txt](https://github.com/nothings/stb/blob/master/docs/stb_howto.txt)

## Functions

| Function                   | Args                                                      | Return Type    | Description         |
|:---------------------------|:----------------------------------------------------------|:---------------|:--------------------|
| hash_table_init            |                                                           | hash_table_t * | Creates a hashtable |
| hash_table_free            | hash_table_t *table                                       | void           | Frees a hashtable   |
| hash_table_add             | hash_table_t *table, char *key, void *value               | int            |Adds a key value pair to a hashtable. Returns the index that the item was added into the table. Returns -1 the item was not added to the table |
| hash_table_get             | hash_table_t *table, char *key                            | void *  | Gets an item from a given hashtable from a given key. Function returns NULL if the item cannot be found. |
| hash_table_set             | hash_table_t *table, char *key, void *value               | void *  | Updates the value of a given item in a hashtable. Function returns NULL if the item with the given key cannot be found. |
| hash_table_remove          | hash_table_t *table, char *key                            | void           | Removes an item from the given hashtable |
| hash_table_free_item       | hash_table_t *table, char *key, void (*free_func)(void *) | void           | Frees the memory for the value of a given item in the table using the free_func function pointer. |
| hash_table_clear_user_data | hash_table_t *table, void (*free_func)(void *)            | void           | Frees the memory for all the values in the hashtable using the free_func funtion pointer  |




