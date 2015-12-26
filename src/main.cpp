#include "common.h"
#include "Tag.h"
#include "Way.h"
#include "Node.h"
#include "Hash.h"
#include "load.h"
#include "Init.h"

void dijkstra (ll, ll);
void Astar (ll, ll);
void spfa (ll, ll);

int main ()
{
    node.add_node (0, 0, 0);
    load_node ();
    load_way ();
    ll s, t;
    while (~scanf ("%lld%lld", &s, &t))
    {
        dijkstra (s, t);
        Astar (s, t);
        spfa (s, t);
    }
    return 0;
}
