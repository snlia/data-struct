#include "common.h"
#include "Node.h"
Hash map_node (600000, 1000007);
int tot_node = 0;
Node node [10];


const double Node::EARTH_RADIUS = 6378.137;
const double Node::PI = 3.1415926535898;

double Node :: rad (double d) { return d * PI / 180.0;}

double Node :: sqr (double d) {return d * d;}

double Node :: dis (double lat_, double lon_)
{
    double radLat1 = rad(lat);
    double radLat2 = rad(lat_);
    double a = radLat1 - radLat2;
    double b = rad(lon) - rad(lon_);

    double s = 2 * asin(sqrt(sqr(sin(a/2.0)) +
                cos(radLat1)*cos(radLat2)*sqr(sin(b/2.0))));
    s = s * EARTH_RADIUS;
    s = round(s * 10000) / 10000;
    return s;
}

double Node :: dis (int Id_)
{
    return dis (node[map_node[Id_]].lat, node[map_node[Id_]].lon);
}

void add_node (int Id, double lat, double lon, bool tag)
{
    node[tot_node] = Node (Id, lat, lon, tag);
    map_node.insert (Id, tot_node);
}
