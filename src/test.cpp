#include "Hash.h"
#include "Node.h"
#include "Tree.h"
#include <cstdio>


int main ()
{
    while (1)
    {
        char tp [10];
        int Id;
        double lat, lon;
        scanf ("%s", tp);
        if (tp[0] == 'N')
        {
            scanf ("%d%lf%lf", &Id, &lat, &lon);
            add_node (Id, lat, lon, 0);
            node[tot_node++] = Node (Id, lat, lon, 0);
        }
        if (tp [0] == 'F')
        {
        }
    }
    return 0;
}
