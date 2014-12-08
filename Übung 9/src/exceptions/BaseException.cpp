#include "BaseException.hpp"

namespace asteroids 
{
   BaseException::BaseException(std::string s) : std::runtime_error(s) {}
} /* namespace BaseException */
