# dynamic-array

Simple dynamic array implementation for the C programming language.

## Quick Start

Copy file_utils.h into your project and include it like this:

``` c
#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "dynamic_array.h"
```
 
This is a stb style header only library. For more information about stb style
headers libraries see [stb_howto.txt](https://github.com/nothings/stb/blob/master/docs/stb_howto.txt)

## Functions

| Function                      | Args                                            | Return Type     | Description |
|-------------------------------|-------------------------------------------------|-----------------|---------------------------------------------------------------------------------------------------------------------|
| dynamic_array_init            |                                                 | dynamic_array * | Creates a dynamic array                                                                                             |
| dynamic_array_free            | dynamic_array *array                            | void            | Frees a dynamic array                                                                                               |
| dynamic_array_set_size        | dynamic_array *array, size_t new_size           | void            | Resizes the array to the number of elements specified in the new_size parameter                                     |
| dynamic_array_add             | dynamic_array *array, void *data                | int             | Adds a new element to the end of the array                                                                          |
| dynamic_array_clear           | dynamic_array *array                            | void            | Clears all values in the array (does not free elements that are heap allocated)                                     |
| dynamic_array_clear_user_data | dynamic_array *array, void (*free_func)(void *) | void            | Clears all values in the array and runs the free_func function pointer to allow heap allocated elements to be freed |
| dynamic_array_insert          | dynamic_array *array, size_t index, void *data  | int             | Inserts an element at provided index. If provided index is greater than the size of the array then -1 is returned   |


