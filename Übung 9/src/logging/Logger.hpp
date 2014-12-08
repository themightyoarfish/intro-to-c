/**
 * @file Logger.hpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 08.12.2014
 */

#ifndef LOGGER_H

#define LOGGER_H

#include "time/Timestamp.hpp"
#include <ostream>

namespace asteroids 
{
   /**
    * @class Logger
    * @brief Singleton Class to log program events
    */
   class Logger 
   {
      public:
         /**
          * @brief Get the singleton instance
          * @return the singleton
          */
         static Logger& instance();

         /**
          * @brief specify destination
          * @param filename File to which log should go.
          */
         void setOutputFile(std::string filename);

         /**
          * @brief reset loggin to stdout
          */
         void setOutputToStdout();

         /**
          * @brief Print log message.
          * @param s Message to log.
          */
         Logger& operator<<(const std::string& s);
      private:
         static Logger* logger;
         static Timestamp stamp;
         std::ostream* out;
         Logger();
         Logger(const Logger& l);
         void operator=(const Logger& l);

   };
} /* namespace asteroids */

#endif /* end of include guard: LOGGER_H */
