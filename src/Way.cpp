#include "Way.h"
#include "Node.h"

Way way;

void Way :: insert (ll Id_, ll Id_node)
{
    int tx = map_way[Id_];
    if (!~tx)
    {
        map_way.insert (Id_, tot);
        Id[tot] = Id_;
        tx = tot++;
    }
    way[tx].push_back (Id_node);
}

std :: vector <ll>& Way :: operator [] (ll Id){return way[map_way[Id]];}

void Way :: build_road ()
{
    for (int i = 0; i < tot; ++i)
        if (tag.find (Id[i], "highway") != "HIT BAD TRAP")
        {
            std :: string s = tag.find (Id[i], "oneway");
            if (s == "yes" || s == "no")
            {
                for (int j = 1; j < (int) way[i].size (); ++j)
                    node[way[i][j - 1]].edge.push_back (std::make_pair (way[i][j], node[way[i][j - 1]].dis (way[i][j])));
                for (int j = 0; j < (int) way[i].size (); ++j)
                    node[way[i][j]].onway = 1;
            }
            if (s == "no")
                for (int j = 1; j < (int) way[i].size (); ++j)
                    node[way[i][j]].edge.push_back (std::make_pair (way[i][j - 1], node[way[i][j]].dis (way[i][j - 1])));
        }
}

void Way::Display (double la, double lo, double ra, double ro)
{
    ll La = (ll) (la * ext), Lo = (ll) (lo * ext), Ra = (ll) (ra * ext), Ro = (ll) (ro * ext);
    for (int i = 0; i < tot; ++i)
        if (tag.find (Id[i], "highway") != "HIT BAD TRAP")
            for (int j = 1; j < (int) way[i].size (); ++j)
            {
                glBegin(GL_LINE_STRIP);
                glVertex2f (((node[way[i][j - 1]].lat - La) / (Ra - La) * 1.9 - 0.95), ((node[way[i][j - 1]].lon - Lo) / (Ro - Lo) * 1.9 - 0.95));
                glVertex2f (((node[way[i][j]].lat - La) / (Ra - La) * 1.9 - 0.95), ((node[way[i][j]].lon - Lo) / (Ro - Lo) * 1.9 - 0.95));
                glEnd();
            }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    way.Display (30.7429085, 121.0037503, 31.4777783, 121.9152437);
    glFlush();
}

void Way::draw_map (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(2000, 2000);
    glutCreateWindow("第一个 OpenGL 程序");
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
}
