#include "common.h"
#include "Tree.h"

int Tree :: new_point ()
{
    ++top;
    T[top].c[top] = T[top].c[1] = T[top].c[2] = T[top].c[3] = T[top].adj = T[top].cnt = 0;
    return top;
}

void Tree :: push (int x, double la, double ra, double lo, double ro)
{
    if (T[x].adj)
    {
        double lat = 0, lon = 0;
        double ma = (la + ra) / 2.0, mo = (la + ra) / 2.0;
        int tp = (lat < ma - eps) * 2 + (lon < mo - eps);
        tp = T[x].c[tp] = new_point ();
        T[tp].cnt = 1; T[tp].adj = T[x].adj;
        T[x].adj = 0;
    }
}

void Tree :: Insert (int Id)
{
    double lat = 0, lon = 0, la = min_lat, ra = max_lat, lo = min_lon, ro = max_lon;
    int *tx = &root;
    while (1)
    {
        push (*tx, la, ra, lo, ro);
        if (!*tx) *tx = new_point ();
        T[*tx].cnt += 1;
        if (T[*tx].cnt == 1)
        {
            T[*tx].adj = Id;
            break;
        }
        double ma = (la + ra) / 2.0, mo = (la + ra) / 2.0;
        int tp = (lat < ma - eps) * 2 + (lon < mo - eps);
        tx = &T[*tx].c[tp];
        if (tp & 1) ro = mo; else lo = mo;
        if (tp & 2) ra = ma; else la = ma;
    }
}
