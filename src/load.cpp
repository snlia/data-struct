#include "load.h"
#include "Node.h"
#include "Tag.h"
#include "Way.h"

void load_node ()
{
    FILE *NODE = fopen ("data/node", "r");
    char tp;
    ll Id, now = 0; double lat, lon;
    char key [50], value [50];
    while (~fscanf (NODE, "%c", &tp))
    {
        if (tp == '=')
        {
            fscanf (NODE, "%lld%lf%lf\n", &Id, &lat, &lon);
            now = Id;
            node.add_node (Id, lat, lon);
        }
        else if (tp == '|')
        {
            fscanf (NODE, "%s%c", key, &tp);
            fgets (value, 50, NODE);
            value[strlen (value) - 1] = 0;
            tag.insert (now, key, value);
        }
        else fgets (value, 50, NODE);
    }
    fclose (NODE);
}

void load_way ()
{
    FILE *WAY = fopen ("data/way", "r");
    char tp;
    ll Id, now = 0;
    char key [50], value [50];
    while (~fscanf (WAY, "%c", &tp))
    {
        if (tp == '=')
        {
            fscanf (WAY, "%lld\n", &Id);
            now = Id;
        }
        else if (tp == '[')
        {
            fscanf (WAY, "%lld\n", &Id);
            way.insert (now, Id);
        }
        else if (tp == '|')
        {
            fscanf (WAY, "%s%c", key, &tp);
            fgets (value, 50, WAY);
            value[strlen (value) - 1] = 0;
            tag.insert (now, key, value);
        }
        else fgets (value, 50, WAY);
    }
    way.build_road ();
    fclose (WAY);
}
