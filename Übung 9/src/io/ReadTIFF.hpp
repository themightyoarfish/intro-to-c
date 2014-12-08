/**
 * ReadTIFF.hpp
 *
 *  @date 14.12.2011
 *  @author Thomas Wiemann
 */

#ifndef READTIFF_HPP_
#define READTIFF_HPP_

#include <string>
using std::string;

#include "BitmapReader.hpp"

namespace asteroids
{

class ReadTIFF : public BitmapReader
{
public:

	/**
	 * @brief Reads the given file
	 */
    ReadTIFF(string filename);
    virtual ~ReadTIFF();

};

}

#endif /* READTIFF_HPP_ */
