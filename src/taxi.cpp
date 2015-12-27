#include "common.h"
#include "Taxi.h"

Hash map_taxi = Hash (2000, 1000007);
int tot_taxi = 0;
std::vector <int> taxi_time [2000];
std::vector <ll> taxi_point [2000];
std::vector <ll> Taxi_way;

void search_taxi (int Id, int s, int t)
{
    int tx = map_taxi[Id];
    if (tx == -1) {printf ("could not find taxi %d\n", Id); return ;}
    int lx = std::lower_bound (taxi_time[tx].begin (), taxi_time[tx].end (), s) - taxi_time[tx].begin ();
    int rx = std::lower_bound (taxi_time[tx].begin (), taxi_time[tx].end (), t) - taxi_time[tx].begin ();
    Taxi_way.clear ();
    for (int i = lx; i <= rx; ++i)
        Taxi_way.push_back (taxi_point[tx][i]);
    puts ("Done!");
}

