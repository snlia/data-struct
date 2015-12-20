#ifndef __NODE_H__
#define __NODE_H__
#include "Hash.h"

class Node
{
    const double EARTH_RADIUS = 6378.137;
    const double PI = 3.1415926535898;
    double rad (double );
    double sqr (double );
    public :
	int Id;
    bool tag;
	double lat, lon;
    double dis (int);
    double dis (double , double);
};

extern Node* node;
extern Hash map_node; 

#endif
