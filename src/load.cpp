#include "load.h"
#include "Node.h"
#include "Tag.h"
#include "Way.h"

void load_node ()
{
    freopen ("data/node", "r", stdin);
    char tp;
    ll Id, now = 0; double lat, lon;
    char key [50], value [50];
    while (~scanf ("%c", &tp))
    {
        if (tp == '=')
        {
            scanf ("%lld%lf%lf\n", &Id, &lat, &lon);
            now = Id;
            node.add_node (Id, lat, lon);
        }
        else if (tp == '|')
        {
            scanf ("%s", key);
            fgets (value, 50, stdin);
            value[strlen (value) - 2] = 0;
            tag.insert (now, key, value);
        }
        else fgets (value, 50, stdin);
    }
}

void load_way ()
{
    freopen ("data/way", "r", stdin);
    char tp;
    ll Id, now = 0;
    char key [50], value [50];
    while (~scanf ("%c", &tp))
    {
        if (tp == '=')
        {
            scanf ("%lld\n", &Id);
            now = Id;
        }
        else if (tp == '[')
        {
            scanf ("%lld\n", &Id);
            way.insert (now, Id);
        }
        else if (tp == '|')
        {
            scanf ("%s", key);
            fgets (value, 50, stdin);
            value[strlen (value) - 2] = 0;
            tag.insert (now, key, value);
        }
        else fgets (value, 50, stdin);
    }
}
