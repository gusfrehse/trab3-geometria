#include "rangetree.h"

#include <assert.h>

#include "util.h"

struct rangetree *rangetree_new(int n, struct vec2 *points)
{
    struct rangetree *rt = malloc(sizeof(struct rangetree));
    assert(rt);

    rt->root = rangetree_build(n, points);

    return rt;
}

struct rangetreenode *rangetree_build(int n, struct vec2 *points)
{
    struct rangetreenode *v = malloc(sizeof(struct rangetreenode));
    assert(v);

    v->tassoc = bsp_new(cmpycoord);

    for (int i = 0; i < n; i++)
        bsp_insert(v->tassoc, points[i]);
    
    if (n == 1)
    {
        v->key = 0.0; //???? TODO: check this
        v->lc = v->rc = NULL;
    }
    else
    {
        int ixmid = n / 2;
        v->key = points[ixmid].x;
        v->lc = rangetree_build(n / 2, points);
        v->rc = rangetree_build(n - (n / 2), points + n / 2);
    }
    
    return v;
}