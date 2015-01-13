/**
 * NavigationRoute.cpp
 *
 *  @date 22.01.2012
 *  @author Thomas Wiemann
 */

#include "NavigationRoute.hpp"

#include <iostream>
using std::endl;
using std::cout;

namespace asteroids
{

NavigationRoute::NavigationRoute(list<Vertex<float> > path)
{
    // Iterator for path points
    list<Vertex<float> >::iterator it;

    m_quadric = gluNewQuadric();

    // Create a display list for the path
    m_pathList = glGenLists(1);
    glNewList(m_pathList, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);
    // Draw path as thick line
    glBegin(GL_LINE_STRIP);
    for(it = path.begin(); it != path.end(); it++)
    {
        Vertex<float> v = *it;
        glVertex3f(v[0], v[1], v[2]);

    }
    glEnd();
    glEndList();

    // Create a display list for the navigation points
    m_navPointList = glGenLists(1);
    glNewList(m_navPointList, GL_COMPILE);
    for(it = path.begin(); it != path.end(); it++)
    {
        Vertex<float> v = *it;
        glColor3f(0.0, 1.0, 0.0);
        glPushMatrix();
        glTranslatef(v[0], v[1], v[2]);
        glutWireSphere(100, 10, 10);
        glPopMatrix();
    }
    glEndList();
}

void NavigationRoute::render()
{
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(5.0);
    glCallList(m_pathList);
    glLineWidth(1.0);
    glCallList(m_navPointList);
    glEnable(GL_LIGHTING);
}

NavigationRoute::~NavigationRoute()
{
    // TODO Auto-generated destructor stub
}

} // namespace asteroids
