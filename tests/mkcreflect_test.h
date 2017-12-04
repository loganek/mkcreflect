#ifndef MKCREFLECT_TEST_H_
#define MKCREFLECT_TEST_H_

#include <string.h>
#include <stdio.h>

#ifdef __linux__
#  define PRINT_COLOR
#endif

#ifdef PRINT_COLOR
#  define COLOR_RED  "\x1B[31m"
#  define COLOR_GREEN  "\x1B[32m"
#  define COLOR_RESET "\033[0m"
#else
#  define COLOR_RED
#  define COLOR_GREEN
#  define COLOR_RESET
#endif

#define PRINT_ERR(...) printf(COLOR_RED "Failure" COLOR_RESET __VA_ARGS__)
#define PRINT_OK(...) printf(COLOR_GREEN "Passed" COLOR_RESET __VA_ARGS__)

#define ASSERT_EQ_(expected, actual, cmp, print_op) do { \
    if (!(cmp)) \
      { \
	PRINT_ERR(" %s %d:\n   * %s != %s\n   * Expected: " print_op	\
          "\n   * Actual: " print_op "\n", __FILE__, __LINE__, \
          #expected, #actual, expected, actual); \
    return 1; \
      } \
    PRINT_OK(" %s == %s\n", #expected, #actual); \
  } while (0)

#define ASSERT_STREQ(expected, actual) ASSERT_EQ_(expected, actual, strcmp(expected, actual) == 0, "%s")
#define ASSERT_UEQ(expected, actual) ASSERT_EQ_(expected, actual, expected == actual, "%lu")
#define ASSERT_EQ(expected, actual) ASSERT_EQ_(expected, actual, expected == actual, "%d")

#define ASSERT_FUNC(FNC_CALL) do { \
    if (FNC_CALL) { \
      return 1; \
    } \
  } while (0)

#endif /* MKCREFLECT_TEST_H_ */
