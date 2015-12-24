#pragma once
#include "common.h"
#include "Hash.h"

extern Hash map_tag;

class Tag
{
    std :: map <std :: string, std :: string> T [800000];
    int tot;
    Hash map_tag ;
    public :
    void insert (ll Id, char *key, char *value)
    {
        int tx = map_tag[Id];
        if (!~tx)
        {
            map_tag.insert (Id, tot);
            T[tot++].insert (std :: make_pair (std :: string (key), std :: string (value)));
        }
    }
    std :: string find (ll Id, std :: string key)
    {
        if (T[map_tag[Id]].find (key) != T[map_tag[Id]].end ())
            return T[map_tag[Id]][key];
        else return "HIT BAD TRAP";
    }
    Tag () {tot = 0; map_tag = Hash (800000, 1000007);}
};

extern Tag tag;
