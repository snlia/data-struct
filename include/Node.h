#pragma once
#include "Hash.h"


class Node
{
    const static double EARTH_RADIUS;
    const static double PI;
    double rad (double );
    double sqr (double );
    public :
    ll lat, lon, Id, fa, Fa;
    bool vis, onway;
    double adj, fadj;
    std :: vector <std::pair <ll, double> > edge;
    double dis (ll);
    double dis (double , double);
    bool inside (ll, ll, ll, ll);
    Node () {}
    Node (ll Id_, double lat_, double lon_) {Fa = fa = Id_; vis = onway = 0; fadj = adj = 0; edge.clear (); Id = Id_; lat = (ll) (lat_ * ext); lon = (ll) (lon_ * ext);}
};

class Nodes
{
    Hash map_node; 
    int tot_node;
    Node node [600000];
    public :
    Nodes () {tot_node = 0; map_node = Hash (600000, 1000007);}
    void add_node (ll , double , double );
    void reset ();
    Node& operator [] (ll Id);
};

extern Nodes node;
ll getf (ll );
