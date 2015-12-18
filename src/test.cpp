#include "Hash.h"

int main ()
{
    Hash T (100, 1000007);
    int tp, x, y;
    while (1)
    {
        scanf ("%d", &tp);
        if (tp) {scanf ("%d%d", &x, &y); T.insert (x, y);}
        else {scanf ("%d", &x); printf ("%d\n", T.find (x));}
    }
}
