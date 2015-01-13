/**
 * NavigationRoute.h
 *
 *  @date 22.01.2012
 *  @author Thomas Wiemann
 */

#ifndef NAVIGATIONROUTE_H_
#define NAVIGATIONROUTE_H_

// Project includes
#include "math/Vertex.hpp"
#include "FixedObject.hpp"

// OpenGL stuff
#include <OpenGL/glu.h>
#include <glut.h>

// STL stuff
#include <list>
using std::list;

namespace asteroids
{

class NavigationRoute : public FixedObject
{
public:
    NavigationRoute(list<Vertex<float> > path);
    virtual ~NavigationRoute();

    virtual void render();

private:
    GLuint          m_pathList;
    GLuint          m_navPointList;
    GLUquadric*     m_quadric;
};

} // namespace asteroids

#endif /* NAVIGATIONROUTE_H_ */
