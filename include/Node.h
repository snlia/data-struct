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
    std :: vector <ll> edge;
    double dis (int);
    double dis (double , double);
    Node () {}
    Node (ll Id_, double lat_, double lon_) {Id = Id_; lat = (ll) (lat_ * ext); lon = (ll) (lon_ * ext);}
};

class Nodes
{
    Hash map_node; 
    public :
    Node node [600000];
    int tot_node;
    Nodes () {tot_node = 0; map_node = Hash (600000, 1000007);/* puts ("abc"); map_node.insert (0, 0); puts ("abc");*/}
    void add_node (ll , double , double );
    Node operator [] (ll Id);
};

extern int tot_node;
extern Nodes node;

