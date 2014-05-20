/* written by ben6 2014-05 */
#ifndef _CLASS_POINT_H
#define _CLASS_POINT_H

extern const void *Point;

struct Point {
    const void *class;
    char *class_name;
    int x;
    int y;
    int (*draw)(void *_self);
};

#endif
