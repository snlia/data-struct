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
    bool tag;
    double dis (int);
    double dis (double , double);
    Node () {}
    Node (ll Id_, double lat_, double lon_, bool tag_) {Id = Id_; lat = (ll) (lat_ * ext); lon = (ll) (lon_ * ext); tag = tag_;}
};

extern Node* node; 
extern Hash map_node; 
extern int tot_node;

void add_node (ll , double , double , bool );
