#include "common.h"
#include "Block.h"

typedef long long ll;

double a [600000];

int main ()
{
    freopen ("test.in", "r", stdin);
//    freopen ("test.out", "w", stdout);
    ll Id;
    double lat, lon;
    node = new Node [600000];
    char tp [10];
    while (~scanf ("%s", tp))
    {
        if (tp[0] == 'N')
        {
            scanf ("%lld%lf%lf", &Id, &lat, &lon);
            add_node (Id, lat, lon, 0);
            blk :: insert (Id);
        }
        if (tp[0] == 'F')
        {
            scanf ("%lf%lf", &lat, &lon);
            ll ans = blk :: find (lat, lon);
            if (ans)
                printf ("%.8lf\n", node[map_node[ans]].dis (lat, lon));
            else puts ("0");
        }
    }
    return 0;
}
