#include "Way.h"
#include "Node.h"

Way way;

void Way :: insert (ll Id_, ll Id_node)
{
    int tx = map_way[Id_];
    if (!~tx)
    {
        map_way.insert (Id_, tot);
        Id[tot] = Id_;
        tx = tot++;
    }
    way[tx].push_back (Id_node);
}

std :: vector <ll>& Way :: operator [] (ll Id){return way[map_way[Id]];}

void Way :: build_road ()
{
    for (int i = 0; i < tot; ++i)
    {
        std :: string s = tag.find (Id[i], "oneway");
        if (s == "yes" || s == "no")
        {
            for (int j = 1; j < (int) way[i].size (); ++j)
                node[way[i][j - 1]].edge.push_back (std::make_pair (way[i][j], node[way[i][j - 1]].dis (way[i][j])));
            for (int j = 0; j < (int) way[i].size (); ++j)
                node[way[i][j]].onway = 1;
        }
        if (s == "no")
            for (int j = 1; j < (int) way[i].size (); ++j)
                node[way[i][j]].edge.push_back (std::make_pair (way[i][j - 1], node[way[i][j]].dis (way[i][j - 1])));
    }
}
