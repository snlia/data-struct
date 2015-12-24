#include "load.h"

void load_node ()
{
    freopen ("data/node", "r", stdin);
    char tp;
    ll Id, now; double lat, lon;
    while (scanf ("%c", &tp))
    {
        if (tp == '=')
        {
            scanf ("%lld%lf%lf", Id, lat, lon);
            now = Id;
        }
    }
}
