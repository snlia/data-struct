#pragma once
#include "Hash.h"


class Node
{
    const static double EARTH_RADIUS;
    const static double PI;
    double rad (double );
    double sqr (double );
    public :
    int Id;
    double lat, lon;
    bool tag;
    double dis (int);
    double dis (double , double);
    Node () {}
    Node (int Id_, double lat_, double lon_, bool tag_) {Id = Id_; lat = lat_; lon = lon_; tag = tag_;}
};

extern Node* node; 
extern Hash map_node; 
extern int tot_node;

void add_node (int , double , double , bool );
