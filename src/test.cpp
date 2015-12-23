#include "common.h"
#include "Block.h"

typedef long long ll;

ll a [600000];

int main ()
{
    freopen ("test.in", "r", stdin);
    freopen ("test.out", "w", stdout);
    
    ll Id;
    double lat, lon;
    node = new Node [600000];
    add_node (0, 0, 0, 0);
    char tp [10];
    /*
    int tot = 0;
    while (~scanf ("%s", tp))
    {
        if (tp[0] == 'N') 
        {
            scanf ("%lld%lf%lf", &Id, &lat, &lon);
            a[tot++] = (ll) (lon * 10000000);
        }
    }
    std :: sort (a, a + tot);
    for (int i = 0; i <= tot/1000; ++i)
        printf ("%lld\n", a[i*1000]);
    */
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
         //   if (ans)
         //       printf ("%.8lf\n", node[map_node[ans]].dis (lat, lon));
         //   else puts ("0");
            printf ("%lld\n", ans);
        }
    }
    return 0;
}
