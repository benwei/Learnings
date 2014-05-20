/* object.c: code from https://github.com/cnkei/ooc/tree/master/ex02 */
#include <assert.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "class.h"
#include "object.h"

static uint32_t object_id = 1;

static void *Object_ctor(void *_self, va_list *app)
{
    struct Object *self = _self;
    const uint32_t id = va_arg(*app, uint32_t);

    if (id) {
            self->object_id = id;
        } else {
                self->object_id = object_id++;
            }

    return self;
}

static void *Object_dtor(void *_self)
{
    struct Object *self = _self;

    self->object_id = 0;

    return self;
}

static void *Object_clone(const void *_self)
{
    const struct Object *self = _self;

    return new(Object, self->object_id);
}

static int Object_differ(const void *_self, const void *_b)
{
    const struct Object *self = _self;
    const struct Object *b = _b;

    if (self == b) {
            return 0;
        }
    if (! b || b->class != Object) {
            return 1;
        }

    return self->object_id != b->object_id;
}

static const struct Class _Object = {
    sizeof(struct Object),
    Object_ctor,
    Object_dtor,
    Object_clone,
    Object_differ
};

const void *Object = &_Object;
