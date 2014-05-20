/* ooc- reference: http://www.cs.rit.edu/~ats/books/ooc.pdf
 * written by ben6 2014-05
 */

#include <stdio.h> /* printf */
#include "class.h"
#include "object.h"
#include "point.h"

int main(int argc, char **argv)
{
    struct Point *point = new(Point, 10, 20);
    struct Point *second = clone(point);

    /* tested with missing y argument, get a ramdon value */
    struct Point *third = new(Point, 99);

    printf("OOC: point (x,y) = (%d,%d)\n", point->x, point->y);
    printf("OOC: data of second (clone from point) and point %s.\n",
            differ(point, second) ? "is differ": "is same" );
    point->x= 12;
    printf("changed OOC: point (x,y) = (%d,%d)\n", point->x, point->y);
    printf("OOC: second (x,y) = (%d,%d)\n", second->x, second->y);
    printf("OOC: third (x, undefined) = (%d,%d), random value on y.\n", third->x, third->y);
    point->draw(point);
    delete(point);
    delete(second);
    delete(third);
    return 0;
}
