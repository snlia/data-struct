#pragma once
#include "common.h"

extern Hash map_tag;

class Tag
{
    std :: map <string, string> T [800000];
    int tot;
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
    std :: string find (ll Id, char *key)
    {
        return T[mag_tag[Id]][string (key)];
    }
    Tag () {tot = 0;}
};

