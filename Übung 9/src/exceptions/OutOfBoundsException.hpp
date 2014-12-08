/**
 * @file OutOfBoundsException.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 08.12.2014
 * @brief Contains OutOfBoundsException class declaration
 */

#ifndef OUTOFBOUNDSEXCEPTION_H

#define OUTOFBOUNDSEXCEPTION_H

#include "BaseException.hpp"

namespace asteroids 
{
   class OutOfBoundsException : public BaseException
   {
      public:
         /**
          * @see BaseException
          */
         OutOfBoundsException(std::string s);
   };
} /* namespace asteroids */

#endif /* end of include guard: OUTOFBOUNDSEXCEPTION_H */
