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
 * Randomizer.cpp
 *
 *  @date 09.12.2012
 *  @author Thomas Wiemann
 */

#include "Randomizer.hpp"

namespace asteroids
{

Randomizer* Randomizer::p_instance = 0;

Randomizer* Randomizer::instance()
{
    if(!Randomizer::p_instance)
    {
        srand(time(0));
        Randomizer::p_instance = new Randomizer;
    }
    return Randomizer::p_instance;
}

float Randomizer::getRandomNumber(float a, float b)
{
    double r = b - a + 1;
    return a + (r * rand()/(RAND_MAX+1.0));
}

Vertex<float> Randomizer::getRandomVertex(float range)
{
    return Vertex<float>(getRandomNumber(-range, range),
                         getRandomNumber(-range, range),
                         getRandomNumber(-range, range));
}


} /* namespace asteroids */
