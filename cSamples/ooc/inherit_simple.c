#include <stdio.h>

struct Shape {
    int type;
};

struct Point {
    struct Shape shape;
    int x, y;
};

struct Line {
    struct Point start;
    struct Point end;
};

int main_inherit()
{
    struct Line line;
    struct Point *point_start = (struct Point *) &line;
    line.start.x = 10;
    line.start.y = 11;
    line.end.x = 20;
    line.end.y = 21;

    printf("Point start(%d, %d)\n", point_start->x, point_start->y);
    printf("Point end (%d, %d)\n", line.end.x, line.end.y);
    return 0;
}
