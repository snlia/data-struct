#include "common.h"
#include "Block.h"
#include "Map.h"
#include "Tag.h"
#include "Way.h"
#include "Node.h"
#include "Hash.h"
#include "load.h"
#include "Init.h"
#include "Taxi.h"

void dijkstra (ll, ll);
void Astar (ll, ll);
void spfa (ll, ll);
void draw_map (int, char **, double, double, double, double);

int main (int argc, char *argv[])
{
    node.add_node (0, 0, 0);
    puts ("Loading nodes...");
    load_node ();
    puts ("Loading ways...");
    load_way ();
    puts ("Loading taxi...");
    load_taxi ();
    puts ("Done!");
    ll s = -1, t = -1;
    int x, Id, h0, m0, s0, h1, m1, s1;
    double la, lo, ra, ro;
    char tp [10];
    char S [1000];
    while (~scanf ("%s", tp))
    {
        if (std::string (tp) == "dijkstra")
        {
            scanf ("%lld%lld", &s, &t);
            dijkstra (s, t);
        }
        if (std::string (tp) == "Astar")
        {
            scanf ("%lld%lld", &s, &t);
            Astar (s, t);
        }
        if (std::string (tp) == "spfa")
        {
            scanf ("%lld%lld", &s, &t);
            spfa (s, t);
        }
        if (std::string (tp) == "range")
        {
            scanf ("%lf%lf%lf%lf", &la, &lo, &ra, &ro);
            blk::search (la, lo, ra, ro);
            printf ("Find %d points.\n", (int) blk::Ans.size ());
        }
        if (std::string (tp) == "neighbour")
        {
            scanf ("%lf%lf", &la, &lo);
            ll ans = blk::find (la, lo);
            printf ("Finding Point with Id: %lld, dis :%.4lf\n", ans, node[ans].dis (la, lo));
        }
        if (std::string (tp) == "fiter")
        {
            scanf ("%s", S);
            blk::fiter (std::string (S));
            printf ("Find %d points.\n", (int) blk::Ans.size ());
        }
        if (std::string (tp) == "near")
        {
            scanf ("%d%lf%lf", &x, &la, &lo);
            blk::near (x, la, lo);
            puts ("done");
        }
        if (std::string (tp) == "list")
            blk::list ();
        if (std::string (tp) == "map")
        {
            scanf ("%lf%lf%lf%lf", &la, &lo, &ra, &ro);
            Map::draw_map (argc, argv, la, lo, ra, ro, s, t);
        }
        if (std::string (tp) == "taxi")
        {
            scanf ("%d%d:%d:%d%d:%d:%d", &Id, &h0, &m0, &s0, &h1, &m1, &s1);
            search_taxi (Id, h0 * 3600 + m0 * 60 + s0, h1 * 3600 + m1 * 60 + s1);
        }
    }
    return 0;
}
