#pragma once

#include "util.h"

#include <stdlib.h>

struct bspnode
{
    struct vec2 key;
    struct bspnode *lc, *rc;
};

struct bsp {
    struct bspnode *root;
    int (*cmpfunc)(struct vec2, struct vec2);
};

struct bsp* bsp_new(int (*cmpfunc)(struct vec2, struct vec2));
void bsp_insert(struct bsp *bsp, struct vec2 v);
struct bspnode* bsp_query(struct bsp *bsp, struct vec2 v);

