#include <cstdio>
#define maxn 1000

char S [maxn];
int main ()
{
    int id, h, m, s, v;
    double lat, lon;
    freopen ("data/shanghai_taxi_20150401.csv", "r", stdin);
    FILE* TAXI = fopen ("data/taxi", "w");
    int now = 0;
    while (~scanf ("%d", &id))
    {
        ++now;
        if (!(now % 100000)) printf ("%d\n", now);
        scanf ("%s", S);
        scanf ("%d:%d:%d,%d,%lf,%lf", &h, &m, &s, &v, &lon, &lat);
        for (int i = 0; i < 6; ++i)
            fgets (S, maxn, stdin);
        fprintf (TAXI, "%d %d %.7lf %.7lf\n", id, h * 3600 + m * 60 + s, lat, lon);
    }
    return 0;
}
