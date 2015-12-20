#include "Hash.h"
#include <cstdio>

int main ()
{
    Hash T (100, 100);
    while (1)
    {
        int x, tp;
        scanf ("%d", &tp);
        if (tp) {scanf ("%d", &x); printf ("%d\n", T[x]);}
        else {scanf ("%d%d", &x, &tp); T.insert (x, tp);}
    }
    return 0;
}
