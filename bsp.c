#include "bsp.h"

#include "util.h"

struct bsp* bsp_new(int (*cmpfunc)(struct vec2, struct vec2))
{
    struct bsp *bsp = malloc(sizeof(struct bsp));
    assert(bsp);
    bsp->root = NULL;
    bsp->cmpfunc = cmpfunc;
    return bsp;
}

void bsp_insert(struct bsp *bsp, struct vec2 v)
{
    struct bspnode *node = bsp->root;
    struct bspnode **ptr = &bsp->root;
    while (node != NULL) {
        if (bsp->cmpfunc(v, node->key)) {
            ptr = &node->lc;
            node = node->lc;
        } else {
            ptr = &node->rc;
            node = node->rc;
        }
    }
    node = malloc(sizeof(struct bspnode));
    node->key = v;
    node->lc = NULL;
    node->rc = NULL;
    *ptr = node;
}

struct bspnode* bsp_query(struct bsp *bsp, struct vec2 v) {
    struct bspnode *node = bsp->root;
    while (node != NULL) {
        if (bsp->cmpfunc(v, node->key)) {
            node = node->lc;
        } else {
            node = node->rc;
        }
    }
    return node;
}