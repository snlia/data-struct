#include "common.h"
#include "Node.h"

typedef std::pair <double, ll> pdi;
static std::priority_queue <pdi, std::vector <pdi>, std::greater <pdi> > Q;

void Astar (ll s, ll t)
{
    node.reset ();
    node[s].adj = 0;
    while (!Q.empty ()) Q.pop ();
    Q.push (std::make_pair (0, s));
    while (!Q.empty ())
    {
        ll x = Q.top ().second;
        if (x == t) {printf ("%.7lfm\n", node[t].adj); 
            return ;}
        Q.pop ();
        if (node[x].vis) continue;
        node[x].vis = 1;
        double now_dis = node[x].adj;
        for (int i = 0; i < (int) node[x].edge.size (); ++i)
        {
            ll tx = node[x].edge[i].first;
            if (node[tx].adj > now_dis + node[x].edge[i].second)
            {
                node[tx].fa = x;
                node[tx].adj = now_dis + node[x].edge[i].second;
                if (tx == t || node[tx].adj + node[tx].dis (t) < node[t].adj)
                    Q.push(std::make_pair (node[tx].adj + node[tx].dis (t), tx));
            }
        }
    }
    puts ("no way!");
}

