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
    clock_t start = clock();
    while (~scanf ("%s", tp))
    {
        if (std::string (tp) == "dijkstra")
        {
            scanf ("%lld%lld", &s, &t);
            start = clock();
            dijkstra (s, t);
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
        }
        if (std::string (tp) == "Astar")
        {
            scanf ("%lld%lld", &s, &t);
            start = clock();
            Astar (s, t);
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
        }
        if (std::string (tp) == "spfa")
        {
            scanf ("%lld%lld", &s, &t);
            start = clock();
            spfa (s, t);
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
        }
        if (std::string (tp) == "range")
        {
            scanf ("%lf%lf%lf%lf", &la, &lo, &ra, &ro);
            start = clock();
            blk::search (la, lo, ra, ro);
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
            printf ("Find %d points.\n", (int) blk::Ans.size ());
        }
        if (std::string (tp) == "neighbour")
        {
            scanf ("%lf%lf", &la, &lo);
            start = clock();
            blk::find (la, lo);
            blk::near (10, la, lo);
            ll ans = blk::Ans[0];
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
            printf ("Finding Point with Id: %lld, dis :%.4lf\n", ans, node[ans].dis (la, lo));
        }
        if (std::string (tp) == "fiter")
        {
            scanf ("%s", S);
            start = clock();
            blk::fiter (std::string (S));
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
            printf ("Find %d points.\n", (int) blk::Ans.size ());
        }
        if (std::string (tp) == "near")
        {
            scanf ("%d%lf%lf", &x, &la, &lo);
            start = clock();
            blk::near (x, la, lo);
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
            puts ("done");
        }
        if (std::string (tp) == "list")
        {
            start = clock();
            blk::list ();
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
        }
        if (std::string (tp) == "map")
        {
            scanf ("%lf%lf%lf%lf", &la, &lo, &ra, &ro);
            start = clock();
            Map::draw_map (argc, argv, la, lo, ra, ro, s, t);
        }
        if (std::string (tp) == "taxi")
        {
            scanf ("%d%d:%d:%d%d:%d:%d", &Id, &h0, &m0, &s0, &h1, &m1, &s1);
            start = clock();
            search_taxi (Id, h0 * 3600 + m0 * 60 + s0, h1 * 3600 + m1 * 60 + s1);
            printf ("using time %.4lf\n", (clock () - start + 0.0) / CLOCKS_PER_SEC); 
        }
        if (std::string (tp) == "taxipoint")
        {
            scanf ("%lf%lf", &la, &lo);
            start = clock();
            blk::find (la, lo);
            blk::near (10, la, lo);
            blk::near_taxi ();
            ll ans = blk::Ans[0];
            printf ("Finding Point with Id: %lld, dis :%.4lf\n", ans, node[ans].dis (la, lo));
        }
    }
    return 0;
}
