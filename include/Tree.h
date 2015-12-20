#include "common.h"

class Tree
{
    const int MOD = 100000007;
    struct tree
    {
        int c [4];
        int adj, cnt;
    };
    int new_point ();
    void push (int , double, double, double, double);
    tree *T;
    int top, root;
    double min_lat, max_lat, min_lon, max_lon;
    public :
    Tree () {};
    Tree (int maxn, int Min_lat, int Min_lon, int Max_lat, int Max_lon)
    {
        top = -1;
        T = new tree [maxn];
        new_point ();
        root = 0;
        min_lat = Min_lat; min_lon = Min_lon; max_lat = Max_lat; max_lon = Max_lon;
    }
    void Insert (int Id);
    ~Tree ()
    {
        delete (T);
    }
};
