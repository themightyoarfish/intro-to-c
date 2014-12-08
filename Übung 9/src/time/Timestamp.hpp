#ifndef TIMESTAMP_H

#define TIMESTAMP_H

#include <iostream>
#include <sys/time.h>

namespace asteroids 
{
   class Timestamp 
   {
      public:
         Timestamp();
         unsigned long getCurrentTimeInMs() const;
         unsigned long getElapsedTimeInMs() const;
         unsigned long getCurrentTimeInS() const;
         unsigned long getElapsedTimeInS() const;
         void resetTimer();
         std::string getElapsedTime() const;
         friend std::ostream& operator<<(std::ostream& os, const Timestamp& ts); // why is friend necessary?

      private:
         unsigned long m_startTime;
   };
} /* namespace asteroids */

#endif /* end of include guard: TIMESTAMP_H */
