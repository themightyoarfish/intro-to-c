/**
 * @file BaseException.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 08.12.2014
 * @brief Contains the BaseException class declaration
 */

 
#ifndef BASEEXCEPTION_H

#define BASEEXCEPTION_H

#include <stdexcept>
#include <string>

namespace asteroids 
{
   /**
    * @class BaseException
    * @brief A base class for exceptions
    */
   class BaseException : public std::runtime_error
   {
      protected:
         /**
          * @brief Constructor
          * @param s Message string
          */
         BaseException(std::string s);
   };
} /* namespace asteroids */

#endif /* end of include guard: BASEEXCEPTION_H */
