
/**
 * FixedObject.h
 *
 *  @date 02.01.2012
 *  @author Thomas Wiemann
 */

#ifndef FIXEDOBJECT_H_
#define FIXEDOBJECT_H_

#include "Renderable.hpp"

namespace asteroids
{

/**
 * @brief   Interface stub to mark object that cannot be moved.
 */
class FixedObject : public Renderable
{
public:
    FixedObject() {}

};

} // namespace asteroids
#endif /* FIXEDOBJECT_H_ */
