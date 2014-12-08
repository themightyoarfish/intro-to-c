/**
 * Renderable.hpp
 *
 *  @date 02.01.2012
 *  @author Thomas Wiemann
 */

#ifndef RENDERABLE_HPP_
#define RENDERABLE_HPP_

namespace asteroids
{

/**
 * @brief Interface class for all objects that support rendering.
 */
class Renderable
{
public:

    /**
     * @brief   Renders the object.
     */
    virtual void render() = 0;
};


} // namespace asteroids
#endif /* RENDERABLE_HPP_ */
