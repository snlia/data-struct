#pragma once
#include "common.h"

class Hash
{
    struct data
    {
        int adj, next;
        ll x;
    };
    ll Mod;
    int Maxn, top;
    int *r;
    data *h;
    public :
    Hash () {};
    Hash (int Maxn_, ll Mod_) 
    {
        Mod = Mod_;
        Maxn = Maxn_;
        top = -1;
        r = new int [Mod];
        h = new data [Maxn];
        memset (r, 255, sizeof (int) * Mod);
    }
    void insert (ll x, int y)
    {
        ll tx = x % Mod;
        for (int p = r[tx]; ~p; p = h[p].next)
            if (h[p].x == x)
                return ;
        h[++top].x =  x; h[top].adj = y; h[top].next = r[tx]; r[tx] = top;
    }
    int operator [] (ll x)
    {
        ll tx = x % Mod;
        for (int p = r[tx]; ~p; p = h[p].next)
            if (h[p].x == x)
                return h[p].adj;
        return -1;
    }
    ~Hash ()
    {
        delete [] r;
        delete [] h;
    }
};
