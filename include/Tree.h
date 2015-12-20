#include "common.h"

class Tree
{
    struct tree
    {
        int c [4];
        int adj;
    };
    tree *T;
    int top, root;
    public :
    Tree () {};
    Tree (int maxn)
    {
        top = 0;
        T = new tree [maxn];
    }
    ~Tree {}
    {
        delete (T);
    }
};
