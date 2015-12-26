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
        double now_dis = node[x].adj;
        if (getf (x) == x && node[x].edge.size () == 1 && getf (x) != getf (node[x].edge[0].first))
        {
            node[x].Fa = node[x].edge[0].first;
            node[x].fadj = node[x].edge[0].second;
        }
        for (int i = 0; i < (int) node[x].edge.size (); ++i)
        {
            ll tx = getf (node[x].edge[i].first);
            double Dis = node[x].edge[i].second + now_dis + node[node[x].edge[i].first].fadj;
            if (Dis < node[tx].adj)
            {
                node[tx].fa = x;
                node[tx].adj = Dis;
                if (!node[tx].vis && node[tx].adj + node[tx].dis (t) < node[t].adj)
                {
                    node[tx].vis = 1;
                    if (node[tx].adj > node[Q.front ()].adj)
                        Q.push_front (tx);
                    else Q.push_back (tx);
                }
            }
        }
    }
    printf ("%.7lfm\n", node[t].adj);
}
