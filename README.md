# mkcreflect
[![Build Status](https://travis-ci.org/loganek/mkcreflect.svg?branch=master)](https://travis-ci.org/loganek/mkcreflect) [![Build status](https://ci.appveyor.com/api/projects/status/aqeb89t5sbf7uxsv?svg=true)](https://ci.appveyor.com/project/loganek/mkcreflect)

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

Also, see [examples](examples).

## Integration to your project
Just copy a **lib/include/mkcreflect.h** file to your project and include it wherever you want to use it.

## Example
There are a few examples in [examples](examples) directory.

## License
Distributed under the [Beerware license](LICENSE).
