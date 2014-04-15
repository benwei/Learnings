#ifndef __TEST_H__
#define __TEST_H__
#include <stdbool.h>

#define TEST_VERSION "v0.1.1003"
extern bool is_big_endian_system_by_pointer(void);

extern bool is_big_endian_system_by_union(void);

#endif // __TEST_H__
