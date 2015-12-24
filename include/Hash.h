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
    std :: vector <int> r;
    std :: vector <data> h;
    public :
    Hash () {};
    Hash (int Maxn_, ll Mod_) 
    {
        Mod = Mod_;
        Maxn = Maxn_;
        top = -1;
        r = std :: vector <int> (Mod, -1);
        h = std :: vector <data> (Maxn);
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
};
