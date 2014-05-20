/* object.h: code from https://github.com/cnkei/ooc/tree/master/ex02 */
#ifndef _CLASS_OBJECT_H
#define _CLASS_OBJECT_H

#include <stdint.h>

extern const void *Object;

struct Object {
    const void *class;
    uint32_t object_id;
};

#endif
