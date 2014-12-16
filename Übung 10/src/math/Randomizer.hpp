/* Copyright (C) 2011 Uni Osnabrück
 * This file is part of the LAS VEGAS Reconstruction Toolkit,
 *
 * LAS VEGAS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * LAS VEGAS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 */

/**
 * Randomizer.hpp
 *
 *  @date 09.12.2012
 *  @author Thomas Wiemann
 */

#ifndef RANDOMIZER_HPP_
#define RANDOMIZER_HPP_

#include "math/Vertex.hpp"
#include <ctime>
#include <cstdlib>

namespace asteroids
{

/**
 * @brief   Helper class to encapsulate random generator fuctions.
 */
class Randomizer
{
private:
    /**
     * @brief   Ctor.
     */
    Randomizer() {};

    static Randomizer* p_instance;

public:
    /**
     * @brief   Instance access method
     */
    static Randomizer* instance();

    /**
     * @brief   Dtor.
     */
    virtual ~Randomizer() {};

    /**
     * @brief   Returns a random number between high and low
     */
    float getRandomNumber(float low, float high);

    /**
     * @brief   Returns a random with coordinated between -range and +range
     */
    Vertex<float> getRandomVertex(float range);
};

} /* namespace asteroids */

#endif /* RANDOMIZER_HPP_ */
