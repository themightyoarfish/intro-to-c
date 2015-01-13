/**
 * Skybox.h
 *
 *  @date 11.12.2011
 *  @author Thomas Wiemann
 */

#ifndef SKYBOX_H_
#define SKYBOX_H_

#include <string>
using std::string;

#include "Texture.hpp"
#include "FixedObject.hpp"

#include <OpenGL/glu.h>

namespace asteroids
{

/**
 * @brief Renders a Skybox with given dimensions
 */
class Skybox
{
public:

    /**
     * @brief Contructor. Build a skybox with the given dimensions
     *
     * @param   width   The width of the box
     * @param   files   6 filenames containing the texture image data
     */
    Skybox(int width, string files[6]);

    /**
     * @brief Dtor.
     */
    virtual ~Skybox();

    /**
     * @brief Renders the Skybox
     */
    virtual void render();

private:

    /// An array containing the sykbox textures
    Texture**       m_textures;

    /// The with of the Skybox
    int             m_width;
};

} // namespace asteroids

#endif /* SKYBOX_H_ */
