/* class.h: code from https://github.com/cnkei/ooc/tree/master/ex02 */
#ifndef _CLASS_H
#define _CLASS_H

#include <stddef.h>

struct Class {
    size_t size;
    void *(*ctor)(void *self, va_list *app);
    void *(*dtor)(void *self);
    void *(*clone)(const void *self);
    int (*differ)(const void *self, const void *b);
};

void *new(const void *_class, ...);
void delete(void *self);
void *clone(const void *self);
int differ(const void *self, const void *b);
size_t sizeOf(const void *self);

#endif
