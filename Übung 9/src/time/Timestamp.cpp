#include "Timestamp.hpp"
#include <cstddef>
#include <stdexcept>
#include <sstream>

namespace asteroids
{

   Timestamp::Timestamp()
   {
      resetTimer();
   }
   unsigned long Timestamp::getCurrentTimeInMs() const
   {
      struct timeval tv;
      struct timezone tz;
      if (gettimeofday(&tv, &tz) == -1)
         throw std::runtime_error("Error while attempting to get system time.");
      return 1000 * tv.tv_sec + (unsigned long) (tv.tv_usec / 1000);      
   }
   unsigned long Timestamp::getElapsedTimeInMs() const
   {
      return getCurrentTimeInMs() - m_startTime;
   }
   unsigned long Timestamp::getCurrentTimeInS() const
   {
      return getCurrentTimeInMs() / 1000;
   }
   unsigned long Timestamp::getElapsedTimeInS() const
   {
      return getElapsedTimeInMs() / 1000;
   }
   void Timestamp::resetTimer()
   {
      m_startTime = getCurrentTimeInMs();
   }
   std::string Timestamp::getElapsedTime() const
   {
      unsigned long elapsed = getElapsedTimeInMs();
      unsigned long hours = elapsed / (1000 * 60 * 60);
      elapsed -= hours * 1000 * 60 * 60;
      unsigned long minutes = elapsed / (1000 * 60);
      elapsed -= minutes * 1000 * 60;
      unsigned long seconds = elapsed / 1000;
      elapsed -= seconds;
      unsigned long milliseconds = elapsed;
      char buffer[17];
      buffer[16] = '\0'; // necessary?
      sprintf(buffer, "[%02lu:%02lu:%02lu - %03lu]", hours, minutes, seconds, milliseconds);
      return std::string(buffer);
   }
   std::ostream& operator<<(std::ostream& os, const Timestamp& ts)
   {
      os << ts.getElapsedTime();
      return os;
   }
} /* namespace ast */
