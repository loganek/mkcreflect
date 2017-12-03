cmake_minimum_required(VERSION 3.0)

project(mkcreflect
    VERSION 0.1.0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=c99 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition")

add_subdirectory(lib)

enable_testing()
add_subdirectory(tests)
