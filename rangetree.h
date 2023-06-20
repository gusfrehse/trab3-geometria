#pragma once

#include <stdlib.h>

#include "util.h"
#include "bsp.h"

struct rangetreenode
{
    double key;
    struct bsp *tassoc;
    struct rangetreenode *lc, *rc;
}; 

struct rangetree
{
    struct rangetreenode *root;
}; 


struct rangetree *rangetree_new(int n, struct vec2 *points);
struct rangetreenode *rangetree_build(int n, struct vec2 *points);