/**
 * TextureFactory.cpp
 *
 *  @date 11.12.2011
 *  @author Thomas Wiemann
 */

#include "TextureFactory.hpp"
#include "ReadPPM.hpp"
#include "ReadTGA.hpp"
#include "ReadJPG.hpp"
#include "BitmapReader.hpp"

#include <iostream>
using std::cout;
using std::endl;

namespace asteroids
{

string TextureFactory::m_basePath;

TextureFactory::TextureFactory()
{
    // TODO Auto-generated constructor stub

}

TextureFactory::~TextureFactory()
{
    // TODO Auto-generated destructor stub
}

TextureFactory& TextureFactory::instance()
{
    // Just crate one instance
    static TextureFactory instance;
    return instance;
}

void TextureFactory::setBasePath(string base)
{
	m_basePath = base;
}

Texture* TextureFactory::getTexture(string filename) const
{
    // A texture object
    Texture* tex = 0;

    string tex_filename = m_basePath + filename;

    // Texture data
    int width = 0;
    int height = 0;
    unsigned char* data = 0;
    BitmapReader* reader = 0;

    // Get file extension
    if(filename.substr(filename.find_last_of(".") + 1) == "ppm")
    {
        reader = new ReadPPM(tex_filename);
    }
    else if(filename.substr(filename.find_last_of(".") + 1) == "tga")
    {
        reader = new ReadTGA(tex_filename);
    }
    else if(filename.substr(filename.find_last_of(".") + 1) == "jpg")
    {
        reader = new ReadJPG(tex_filename);
    }

    if(reader)
    {
    	data = reader->getPixels();
    	width = reader->getWidth();
    	height = reader->getHeight();
    }

    // Check data and create new texture if possible
    if(data != 0 && width != 0 && height != 0)
    {
        tex = new Texture(data, width, height);
    }
    else
    {
        cout << "TextureFactory: Unable to read file " << tex_filename << "." << endl;
    }

    return tex;
}

}

