#include "Node.h"
#include "Block.h"
Nodes node;

const double Node::EARTH_RADIUS = 6378.137;
const double Node::PI = 3.1415926535898;
double Node :: rad (double d) { return d * PI / 180.0;}

double Node :: sqr (double d) {return d * d;}

double Node :: dis (double lat_, double lon_)
{
    double radLat1 = rad((lat + 0.0) / ext);
    double radLon1 = rad((lon + 0.0) / ext);
    double radLat2 = rad(lat_);
    double radLon2 = rad(lon_);
    double x1 = EARTH_RADIUS * cos (radLat1) * cos (radLon1);
    double y1 = EARTH_RADIUS * cos (radLat1) * sin (radLon1);
    double z1 = EARTH_RADIUS * sin (radLat1);
    double x2 = EARTH_RADIUS * cos (radLat2) * cos (radLon2);
    double y2 = EARTH_RADIUS * cos (radLat2) * sin (radLon2);
    double z2 = EARTH_RADIUS * sin (radLat2);
    double theta = acos ((x1 * x2 + y1 * y2 + z1 * z2) / sqrt ((sqr (x1) + sqr (y1) + sqr (z1)) * (sqr (x2) + sqr (y2) + sqr (z2))));
    return EARTH_RADIUS * theta * 1000;
}

double Node :: dis (ll Id_)
{
    return dis ((node[Id_].lat + 0.0) / ext, (node[Id_].lon + 0.0) / ext);
}


bool Node :: inside (ll la, ll lo, ll ra, ll ro) {return (lat <= ra) && (lat >= la) && (lon <= ro) && (lon >= lo);}

void Nodes :: add_node (ll Id, double lat, double lon)
{
    node[tot_node] = Node (Id, lat, lon);
    map_node.insert (Id, tot_node); ++tot_node;
}

void Nodes::build_block ()
{
    for (int i = 0; i < tot_node; ++i)
        blk::insert (node[i].Id);
}

void Nodes::cksize ()
{
    double min_lat = 10000, min_lon = 1000, max_lat = -1000, max_lon = -1000;
    for (int i = 0; i < tot_node; ++i)
        if (node[i].onway)
        {
            min_lon = std::min (min_lon, (node[i].lon + 0.0) / ext);
            min_lat = std::min (min_lat, (node[i].lat + 0.0) / ext);
            max_lon = std::max (max_lon, (node[i].lon + 0.0) / ext);
            max_lat = std::max (max_lat, (node[i].lat + 0.0) / ext);
        }
    printf ("%.7lf %.7lf %.7lf %.7lf", min_lat, min_lon, max_lat, max_lon);
}

void Nodes :: reset () {for (int i = 0; i < tot_node; ++i) node[i].adj = 10000007, node[i].vis = 0, node[i].Fa = node[i].fa = node[i].Id, node[i].fadj = 0;}

ll getf (ll Id) 
{
    if (node[Id].Fa == Id) return Id;
    ll tx = getf (node[Id].Fa);
    node[Id].fadj += node[node[Id].Fa].fadj;
    return node[Id].Fa = tx;
}

Node& Nodes :: operator [] (ll Id) {return node[map_node[Id]];}
