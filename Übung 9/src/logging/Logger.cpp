#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>

namespace asteroids 
{
   Timestamp Logger::stamp;
   Logger* Logger::logger = NULL;
   Logger::Logger()
   {
      setOutputToStdout();
   }

   Logger& Logger::operator<<(const std::string& s) 
   {
      *out << stamp << " - " << s << std::endl;
      return *this;
   }

   void Logger::setOutputFile(std::string filename)
   {
      std::ofstream file(filename.c_str());
      out = &file;
   }

   void Logger::setOutputToStdout()
   {
      out = &std::cout;
   }

   Logger& Logger::instance()
   {
      if (logger == NULL) 
         logger = new Logger;
      return *logger;
   }
} /* namespace asteroids */
