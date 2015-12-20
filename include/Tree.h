#pragma once
#include "common.h"
#include "Node.h"

class Tree
{
    const int MOD = 100000007;
    struct tree
    {
        int c [4];
        int adj, cnt;
    };
    struct data
    {
        int x;
        double lo, la, ro, ra;
    };
    int new_point ();
    void push (int , double, double, double, double);
    tree *T;
    data *q;
    int top, root;
    double min_lat, max_lat, min_lon, max_lon;
    public :
    Tree () {};
    Tree (int maxn, int Min_lat, int Min_lon, int Max_lat, int Max_lon)
    {
        top = -1;
        T = new tree [maxn];
        q = new data [maxn];
        new_point ();
        root = 0;
        min_lat = Min_lat; min_lon = Min_lon; max_lat = Max_lat; max_lon = Max_lon;
    }
    int Find (double, double);
    void Insert (int Id);
    ~Tree ()
    {
        delete (T);
    }
};

