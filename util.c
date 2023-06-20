#include "util.h"

int cmpxcoord(struct vec2 a, struct vec2 b)
{
    return a.x <= b.x;
}

int cmpycoord(struct vec2 a, struct vec2 b)
{
    return a.y <= b.y;
}