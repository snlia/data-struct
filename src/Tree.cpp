#include "common.h"
#include "Tree.h"
 
const int Tree :: MOD = 100000007;
int Tree :: new_point ()
{
    ++top;
    T[top].c[0] = T[top].c[1] = T[top].c[2] = T[top].c[3] = T[top].adj = T[top].cnt = 0;
    return top;
}

void Tree :: push (int x, double la, double ra, double lo, double ro)
{
    if (T[x].adj)
    {
        double lat = node[map_node[T[x].adj]].lat, lon = node[map_node[T[x].adj]].lon;
        double ma = (la + ra) / 2.0, mo = (lo + ro) / 2.0;
        int tp = (lat < ma - eps) * 2 + (lon < mo - eps);
        tp = T[x].c[tp] = new_point ();
        T[tp].cnt = 1; T[tp].adj = T[x].adj;
        T[x].adj = 0;
    }
}

void Tree :: Insert (int Id)
{
    double lat = node[map_node[Id]].lat, lon = node[map_node[Id]].lon, la = min_lat, ra = max_lat, lo = min_lon, ro = max_lon;
    int *tx = &root;
    while (1)
    {
        push (*tx, la, ra, lo, ro);
        if (!*tx) *tx = new_point ();
        T[*tx].cnt += 1;
        if (T[*tx].cnt == 1)
        {
            T[*tx].adj = Id;
            break;
        }
        double ma = (la + ra) / 2.0, mo = (lo + ro) / 2.0;
        int tp = (lat < ma - eps) * 2 + (lon < mo - eps);
        tx = &T[*tx].c[tp];
        if (tp & 1) ro = mo; else lo = mo;
        if (tp & 2) ra = ma; else la = ma;
    }
}

int Tree :: Find (double lat, double lon)
{
    double la = min_lat, ra = max_lat, lo = min_lon, ro = max_lon, xla = lat - 0.00525, xra = lat + 0.00525, xlo = lon - 0.05115, xro = lon + 0.05115;
    int ans = 0; q[0].x = root; q[0].lo = lo; q[0].ro = ro; q[0].la = la; q[0].ra = ra;
    int tail = 0;
 //   puts ("abc");
    for (int head = 0, x = q[0].x; head <= tail; x = q[++head].x)
    {
//        printf ("%d\n", T[x].cnt);
        if (T[x].adj)
        {
            double Lat = node[map_node[T[x].adj]].lat, Lon = node[map_node[T[x].adj]].lon;
            if ((Lat < xra && Lat > xla && Lon < xro && Lon > xlo) && (!ans || node[map_node[ans]].dis (lat, lon) > node[map_node[T[x].adj]].dis (lat, lon)))
            {
                ans = T[x].adj;
/*                xla = std :: max (std :: min (lat * 2 - node[map_node[T[x].adj]].lat, node[map_node[T[x].adj]].lat), xla);
                xra = std :: min (std :: max (lat * 2 - node[map_node[T[x].adj]].lat, node[map_node[T[x].adj]].lat), xra);
                xlo = std :: max (std :: min (lon * 2 - node[map_node[T[x].adj]].lon, node[map_node[T[x].adj]].lon), xlo);
                xro = std :: min (std :: max (lon * 2 - node[map_node[T[x].adj]].lon, node[map_node[T[x].adj]].lon), xro);*/
            }
            continue;
        }
        for (int tp = 0; tp < 4; ++tp)
            if (T[x].c[tp] && T[T[x].c[tp]].cnt)
            {
                lo = q[head].lo; ro = q[head].ro; la = q[head].la; ra = q[head].ra;
                double ma = (la + ra) / 2.0, mo = (lo + ro) / 2.0;
                if (tp & 1) ro = mo; else lo = mo;
                if (tp & 2) ra = ma; else la = ma;
                if (ra < xla) continue;
                if (ro < xlo) continue;
                if (la > xra) continue;
                if (lo > xro) continue;
                q[++tail].x = T[x].c[tp];
                q[tail].lo = lo; q[tail].ro = ro; q[tail].la = la; q[tail].ra = ra;
            }
    }
    return ans;
}
