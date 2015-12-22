#include "Hash.h"
#include "Node.h"
#include "Tree.h"
#include <cstdio>


int main ()
{
    freopen ("test.in", "r", stdin);
    freopen ("test.out", "w", stdout);
    node = new Node [600000];
    Tree tree = Tree (600000, 30.8822, 121.142, 31.4521, 121.892);
    char tp [10];
    int tot;
    while (~scanf ("%s", tp))
    {
        ++tot;
        if (tot % 10000 == 0) printf ("%d\n", tot);
        int Id;
        double lat, lon;
        if (tp[0] == 'N')
        {
            scanf ("%d%lf%lf", &Id, &lat, &lon);
            if (lat <= 31.4521 && lat >= 30.8822 && lon <= 121.892 && lon >= 121.142)
            {
                int ans = tree.Find (lat, lon);
                if (!ans || node[map_node[ans]].dis (lat, lon) > eps)
                {
                    add_node (Id, lat, lon, 0);
                    tree.Insert (Id);
                }
            }
        }
        if (tp [0] == 'F')
        {
            scanf ("%lf%lf", &lat, &lon);
            int ans = tree.Find (lat, lon);
            if (ans)
                printf ("%.8lf\n", node[map_node[ans]].dis (lat, lon));
            else puts ("0");
        }
    }
    return 0;
}
