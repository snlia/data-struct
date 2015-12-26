#pragma once
#include "Hash.h"


class Node
{
    const static double EARTH_RADIUS;
    const static double PI;
    double rad (double );
    double sqr (double );
    public :
    ll lat, lon, Id;
    bool vis;
    double adj;
    std :: vector <std::pair <ll, double> > edge;
    double dis (ll);
    double dis (double , double);
    Node () {}
    Node (ll Id_, double lat_, double lon_) {Id = Id_; lat = (ll) (lat_ * ext); lon = (ll) (lon_ * ext);}
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

