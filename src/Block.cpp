#include "Block.h"
#include "Tag.h"

namespace blk{
    std::vector <ll> Ans;
    double Lat_, Lon_;
}

void blk :: insert (ll Id)
{
    int l = 0, r = MAX_LEN - 1;
    ll lon = node[Id].lon;
    while (l != r) {int m = (l + r + 1) >> 1; if (lon >= Par[m]) l = m; else r = m - 1;}
    ll lat = node[Id].lat;
    Block *p = T + l;
    for (; p->next != NULL && p->rx < lat; p = p->next);
    p->push (Id);
}

void blk::fiter (std::string S)
{
    int tot = 0;
    for (int i = 0; i < (int) Ans.size (); ++i)
        if (tag.fiter (Ans[i], S))
            Ans[tot++] = Ans[i];
    Ans.resize (tot);
}

bool blk::cmp (ll Id_a, ll Id_b)
{
    return node[Id_a].dis (Lat_, Lon_) < node[Id_b].dis (Lat_, Lon_);
}

void blk::near (int x, double lat, double lon)
{
    Lat_ = lat; Lon_ = lon;
    std::sort (Ans.begin (), Ans.end (), cmp);
    if (x < (int) Ans.size ()) Ans.resize (x);
}

void blk::list () {for (int i = 0; i < (int) Ans.size (); ++i) printf ("Id :%lld\n", Ans[i]);}

ll blk :: ck_block (int x, double lat, double lon)
{
    Block *p = T + x;
    ll Lat = (ll) ((lat + 0.0) * ext);
    Block *pp = p; bool flag = 0;
    for (; p->next != NULL && p->rx < Lat; p = p->next)
    {
        if (flag) pp = p->next;
        flag = 1;
    }
    Block *ppp = p->next;
    ll ans1 = pp->check (lat, lon);
    ll ans2 = p->check (lat, lon);
    ll ans = node[ans1].dis (lat, lon) < node[ans2].dis (lat, lon) ? ans1 : ans2;
    if (ppp != NULL) 
    {
        ll ans3 = ppp-> check (lat, lon);
        ans = node[ans].dis (lat, lon) < node[ans3].dis (lat, lon) ? ans : ans3;
    }
    return ans;
}

ll blk :: find (double lat, double lon)
{
    int l = 0, r = MAX_LEN - 1;
    ll Lon = (ll) ((lon + 0.0) * ext);
    while (l != r) {int m = (l + r + 1) >> 1; if (Lon >= Par[m]) l = m; else r = m - 1;}
    ll ans1 = ck_block (std :: max (l - 1, 0), lat, lon);
    ll ans2 = ck_block (l, lat, lon);
    ll ans = node[ans1].dis (lat, lon) < node[ans2].dis (lat, lon) ? ans1 : ans2;
    ll ans3 = ck_block (std :: min (l + 1, MAX_LEN - 1), lat, lon);
    ans = node[ans].dis (lat, lon) < node[ans3].dis (lat, lon) ? ans : ans3;
    Ans.clear ();
    Ans.push_back (ans);
    return ans;
}

void blk :: search (double La, double Lo, double Ra, double Ro)
{
    ll la = (ll) (La * ext), lo = (ll) (Lo * ext), ra = (ll) (Ra * ext), ro = (ll) (Ro * ext);
    int i = 0;
    Ans.clear ();
    while (i < MAX_LEN - 1 && Par[i + 1] <= lo) ++i;
    for (; i < MAX_LEN && Par[i]<= ro; ++i)
        for (Block *p = T + i; p != NULL; p = p->next)
            if ((p->lx <= ra && p->lx >= la) || (p->rx <= ra && p->rx >= la))
                p->load (la, lo, ra, ro);
}

bool Block :: cmp (ll Id_a, ll Id_b)
{
    return node[Id_a].lat < node[Id_b].lat;
}

void Block :: load (ll la, ll lo, ll ra, ll ro)
{
    for (int i = 0; i < (int) adj.size (); ++i)
        if (node[adj[i]].inside (la, lo, ra, ro))
            blk::Ans.push_back (adj[i]);
}

void Block :: push (ll Id)
{
    adj.push_back (Id);
    int poi = 0;
    for (; cmp (adj[poi], Id); ++poi);
    for (int i = (int) adj.size () - 1; i != poi; --i)
        adj[i] = adj[i - 1];
    adj[poi] = Id;
    if (adj.size () > MAX_SIZE)
    {
        Block *p = new Block;
        for (int i = MAX_SIZE / 2; i < (int) adj.size (); ++i)
            p->adj.push_back (adj[i]);
        adj.resize (MAX_SIZE / 2);
        p->lx = node[p->adj[0]].lat;
        p->rx = node[*p->adj.rbegin()].lat;
        p->next = next;
        next = p;
        lx = node[adj[0]].lat;
        rx = node[*adj.rbegin ()].lat;
        p = next;
    }
    lx = node[adj[0]].lat;
    rx = node[*adj.rbegin ()].lat;
}

ll Block :: check (double lat, double lon)
{
    if (!adj.size ()) return 0;
    ll ans = adj[0];
    for (int i = 1; i < (int) adj.size (); ++i)
    {
        if (node[adj[i]].dis (lat, lon) < node[ans].dis (lat, lon))
            ans = adj[i];
    }
    return ans;
}

