/**
 * TextureFactory.h
 *
 *  @date 11.12.2011
 *  @author Thomas Wiemann
 */

#ifndef TEXTUREFACTORY_H_
#define TEXTUREFACTORY_H_

#include <string>
using std::string;

#include "rendering/Texture.hpp"

namespace asteroids
{

class TextureFactory
{
protected:

    /**
     * @brief Constructor
     */
    TextureFactory();

    /**
     * @brief Destructor
     */
    virtual ~TextureFactory();

public:

    /**
     * @brief   Returns a new texture if the file contains readable
     *          image data or a null point if the file couldn't be parsed
     */
    Texture* getTexture(string filename) const;

    /**
     * @brief Sets the base path for loading Textures
     */
    static void setBasePath(string base);

    /**
     * @brief   Returns the singleton instance
     */
    static TextureFactory& instance();

    static string m_basePath;
};

}
#endif /* TEXTUREFACTORY_H_ */
