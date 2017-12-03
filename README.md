# mkcreflect
[![Build Status](https://travis-ci.org/loganek/mkcreflect.svg?branch=master)](https://travis-ci.org/loganek/mkcreflect)

A reflection library for C

## Features
This library allows you to inspect your data structures at runtime:
 * field types
 * field names
 * size of array fields
 * size of field

## Documentation
There's only one public macro which you should use:
```c
MKCREFLECT_DEFINE_STRUCT(get_info_function_name, StructName,
    (DATA_TYPE, FIELD1_NAME, C_TYPE1[, ARRAY_SIZE_1])[,
    (DATA_TYPE, FIELD2_NAME, C_TYPE2[, ARRAY_SIZE_2])[, ...])
```
 * **get_info_function_name** - function name which returns information about your structure.
 * **StructName** - name of your structure
 * **(DATA_TYPE, FIELD1_NAME, C_TYPE1[, ARRAY_SIZE_1])** - comma-separated list of fields in the structure
   * **DATA_TYPE** - type of field (INTEGER, STRING or STRUCT)
   * **FIELD_NAME** - name of the field
   * **C_TYPE** - type of the field (e.g. int, uint64, char, etc.)
   * **ARRAY_SIZE** - size of array, if a field is an array

See example below for clarification.

## Integration to your project
Just copy a **lib/include/mkcreflect.h** to your project and include it to the file where you want to use it.

## Example
```c
#include <mkcreflect_test.h>
#include <stdio.h>

MKCREFLECT_DEFINE_STRUCT(get_test_struct_type_info, TestStruct,
    (INTEGER, int, int_field),
    (STRING, char, array_field, 20),
    (INTEGER, size_t, size_field))

int main(int argc, char** argv)
{
    MKCREFLECT_TypeInfo* info = get_test_struct_type_info();

    for (size_t i = 0; i < info->fields_count; i++)
    {
        MKCREFLECT_FieldInfo* field = &info->fields[i];
        printf(" * %s: %s (total size: %lu)\n", field->field_name, field->field_type, field->size);
        if (field->array_size != -1)
        {
            printf("   (is array, number of elements: %d)\n", field->array_size);
        }
    }

    return 0;
}
```
##### Output:
```bash
 * int_field: int (total size: 4)
 * array_field: char (total size: 20)
   (is array, number of elements: 20)
 * size_field: size_t (total size: 8)
```

## License
Distributed under the [Beerware license](LICENSE).
