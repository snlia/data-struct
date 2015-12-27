#pragma once
#include "Hash.h"
#include "Tag.h"

class Way
{
    Hash map_way;
    int tot;
    public :
    std :: vector <ll> way [80000];
    ll Id [80000];
    void insert (ll , ll );
    void build_road ();
    void draw_map (int, char **);
    void Display (double, double, double, double);
    std :: vector <ll>& operator [] (ll );
    Way (){tot = 0; map_way = Hash (80000, 1000007);}
};

extern Way way;
