#include "common.h"
#include "Node.h"

void spfa (ll s, ll t)
{
    std::deque <ll> Q;
    Q.clear ();
    Q.push_back (s);
    node.reset ();
    node[s].adj = 0;
    while (!Q.empty ())
    {
        ll x = Q.front (); Q.pop_front ();
        node[x].vis = 0;
        for (int i = 0; i < node[x].edge.size (); ++i)
        {
            ll tx = node[x].edge[i].first;
            if (node[x].edge[i].second + node[x].adj < node[tx].adj)
            {
                node[tx].adj = node[x].edge[i].second + node[x].adj;
                if (!node[tx].vis)
                {
                    node[tx].vis = 1;
                    if (node[tx].adj > node[Q.front ()].adj)
                        Q.push_front (tx);
                    else Q.push_back (tx);
                }
            }
        }
    }
    printf ("%.7lf\n", node[t].adj);
}
