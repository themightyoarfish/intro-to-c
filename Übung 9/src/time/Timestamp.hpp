/**
 * @file Timestamp.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 08.12.2014
 */

 
#ifndef TIMESTAMP_H

#define TIMESTAMP_H

#include <iostream>
#include <sys/time.h>

namespace asteroids 
{
   /**
    * @class Timestamp
    * @brief Represents a point in time.
    */
   class Timestamp 
   {
      public:
         /**
          * @brief Constructor. Time is initialised to current system time.
          */
         Timestamp();

         /**
          * @brief Get current system time.
          * @return Current system time in milliseconds (from UNIX epoch)
          */
         unsigned long getCurrentTimeInMs() const;

         /**
          * @brief Get time elapsed since instance creation.
          * @return The time elapsed since instance creation in milliseconds
          * (from UNIX epoch)
          */
         unsigned long getElapsedTimeInMs() const;

         /**
          * @see Timestamp::getCurrentTimeInMs()
          */
         unsigned long getCurrentTimeInS() const;

         /**
          * @see Timestamp::getElapsedTimeInMs()
          */
         unsigned long getElapsedTimeInS() const;

         /**
          * @brief Reset the timer to current system time.
          */
         void resetTimer();

         /**
          * @brief Get string representation of time elapsed since creation.
          * @return The elapsed time as a string.
          */
         std::string getElapsedTime() const;

         /**
          * @brief Operator to print to a stream.
          */
         friend std::ostream& operator<<(std::ostream& os, const Timestamp& ts); // why is friend necessary?

      private:
         unsigned long m_startTime;
   };
} /* namespace asteroids */

#endif /* end of include guard: TIMESTAMP_H */
