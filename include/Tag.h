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
            T[tot].insert (std :: make_pair (std :: string (key), std :: string (value)));
            tot++;
        }
        else 
            T[tx].insert (std :: make_pair (std :: string (key), std :: string (value)));
    }
    bool fiter (ll Id, std::string S)
    {
        int tx = map_tag[Id];
        if (tx == -1) return 0;
        for (std::map<std::string, std::string>::iterator i = T[tx].begin (); i != T[tx].end (); ++i)
            if (i->second.find (S) != std::string::npos)
                return 1;
        return 0;
    }
    std :: string find (ll Id, std :: string key)
    {
        if (map_tag[Id] == -1) return "HIT BAD TRAP";
        if (T[map_tag[Id]].find (key) != T[map_tag[Id]].end ())
            return T[map_tag[Id]][key];
        else return "HIT BAD TRAP";
    }
    Tag () {tot = 0; map_tag = Hash (800000, 1000007);}
};

extern Tag tag;
