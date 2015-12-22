#include "Block.h"

void blk :: insert (ll Id)
{
    int l = 0, r = 500;
    ll lon = node[map_node[Id]].lon;
    while (l != r) {int m = (l + r + 1) >> 1; if (lon >= Par[m]) l = m; else r = m - 1;}
    ll lat = node[map_node[Id]].lat;
    Block *p = T + l;
        for (; p->next != NULL && p->next->lx >= lat; p = p->next);
    p->push (Id);
}

ll blk :: ck_block (int x, double lat, double lon)
{
    Block *p = T + x;
    ll Lat = (ll) ((lat + 0.0) * ext);
    Block *pp = p; bool flag = 0;
    for (; p->next != NULL && p->next->lx >= Lat; p = p->next)
    {
        if (flag) pp = p->next;
        flag = 1;
    }
    Block *ppp = p->next;
    ll ans1 = pp->check (lat, lon);
    ll ans2 = p->check (lat, lon);
    ll ans = node[map_node[ans1]].dis (lat, lon) < node[map_node[ans2]].dis (lat, lon) ? ans1 : ans2;
    if (ppp != NULL) 
    {
        ll ans3 = ppp-> check (lat, lon);
        ans = node[map_node[ans]].dis (lat, lon) < node[map_node[ans3]].dis (lat, lon) ? ans : ans3;
    }
    return ans;
}

ll blk :: find (double lat, double lon)
{
    int l = 0, r = 500;
    ll Lon = (ll) ((lon + 0.0) * ext);
    while (l != r) {int m = (l + r + 1) >> 1; if (Lon >= Par[m]) l = m; else r = m - 1;}
    ll ans1 = ck_block (std :: max (l - 1, 0), lat, lon);
    ll ans2 = ck_block (l, lat, lon);
    ll ans = node[map_node[ans1]].dis (lat, lon) < node[map_node[ans2]].dis (lat, lon) ? ans1 : ans2;
    ll ans3 = ck_block (std :: min (l + 1, 500), lat, lon);
    ans = node[map_node[ans]].dis (lat, lon) < node[map_node[ans3]].dis (lat, lon) ? ans : ans3;
    return ans;
}

bool Block :: cmp (ll Id_a, ll Id_b)
{
    return node[map_node[Id_a]].lat < node[map_node[Id_b]].lat;
}

void Block :: push (ll Id)
{
    adj.push_back (Id);
    std :: sort (adj.begin (), adj.end (), cmp);
    if (adj.size () > MAX_SIZE)
    {
        Block *p = new Block;
        p->lx = node[map_node[adj[MAX_SIZE / 2]]].lat;
        p->rx = node[map_node[*adj.rbegin ()]].lat;
        for (int i = MAX_SIZE / 2; i < (int) adj.size (); ++i)
            p->adj.push_back (adj[i]);
        adj.resize (MAX_SIZE / 2);
        p->next = next;
        next = p;
    }
}

ll Block :: check (double lat, double lon)
{
    ll ans = adj[0];
    for (int i = 1; i < (int) adj.size (); ++i)
        if (node[map_node[adj[i]]].dis (lat, lon) < node[map_node[ans]].dis (lat, lon))
            ans = adj[i];
    return ans;
}
