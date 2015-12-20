#include "common.h"
#include "node.h"
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
