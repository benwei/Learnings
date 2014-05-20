#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <Point.h>

#include "class.h"
#include "Point.h"

static void *Point_ctor(void *_self, va_list *app)
{
    struct Point *self = _self;
    int x = va_arg(*app, int);
    /* FIXME: how to check there is missing y argument?? */
    int y = va_arg(*app, int);

    self->x = x;
    self->y = y;
    return self;
}

static void *Point_dtor(void *_self)
{
    struct Point *self = _self;
    return self;
}

static void *Point_clone(const void *_self)
{
    const struct Point *self = _self;

    return new(Point, self->x, self->y);
}

static int Point_differ(const void *_self, const void *_b)
{
    const struct Point *self = _self;
    const struct Point *b = _b;

    if (self == b) {
        return 0;
    }

    if (! b || b->class != Point) {
        return 1;
    }

    return (self->x != b->x) || (self->y != b->y);
}

static const struct Class _Point = {
    sizeof(struct Point),
    Point_ctor,
    Point_dtor,
    Point_clone,
    Point_differ
};

const void *Point = &_Point;
