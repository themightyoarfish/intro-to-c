/**
 * @file DivisionByZeroException.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 08.12.2014
 * @brief Contains DivisionByZeroException class declaration
 */

#ifndef DIVISIONBYZEROEXCEPTION_H

#define DIVISIONBYZEROEXCEPTION_H

#include "BaseException.hpp"

namespace asteroids 
{
   /**
    * @class DivisionByZeroException
    * @brief A class for runtime errors due to division by zero.
    */
   class DivisionByZeroException : public BaseException
   {
      public:
         /**
          * @see BaseException
          */
         DivisionByZeroException(std::string s);
   };
} /* namespace asteroids */


#endif /* end of include guard: DIVISIONBYZEROEXCEPTION_H */
