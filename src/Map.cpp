#include "common.h"
#include "Taxi.h"
#include "Block.h"
#include "Map.h"
#include "Way.h"
#include "Node.h"

namespace Map
{
    double la, lo, ra, ro;
    ll s, t;
};

void Map::myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    way.Display (la, lo, ra, ro);
    ll La = (ll) (la * ext), Lo = (ll) (lo * ext), Ra = (ll) (ra * ext), Ro = (ll) (ro * ext);
    if (s != -1)
    {
        glColor3f(0.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for (ll x = t; ; x = node[x].fa)
        {
            glVertex2f (((node[x].lat - La + 0.0) / (Ra - La) * 1.9 - 0.95), ((node[x].lon - Lo + 0.0) / (Ro - Lo) * 1.9 - 0.95));
            if (x == s) break;
        }
        glEnd();
    }
    if (blk::Ans.size ())
    {
        glColor3f(1.0f, 0.0f, 1.0f);
        glPointSize(4.0f);
        glBegin(GL_POINTS);
        for (int i = 0; i < blk::Ans.size (); ++i)
            glVertex2f (((node[blk::Ans[i]].lat - La + 0.0) / (Ra - La) * 1.9 - 0.95), ((node[blk::Ans[i]].lon - Lo + 0.0) / (Ro - Lo) * 1.9 - 0.95));
        glEnd();
    }
    if (Taxi_way.size ())
    {
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < (int) Taxi_way.size (); ++i)
            glVertex2f (((node[Taxi_way[i]].lat - La + 0.0) / (Ra - La) * 1.9 - 0.95), ((node[Taxi_way[i]].lon - Lo + 0.0) / (Ro - Lo) * 1.9 - 0.95));
        glEnd();

    }
    glFlush();
}

void Map::draw_map (int argc, char **argv, double La, double Lo, double Ra, double Ro, ll S, ll T)
{
    la = La, lo = Lo, ra = Ra, ro = Ro;
    s = S, t = T;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(2000, 2000);
    glutCreateWindow("Map");
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
}
