#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <typeinfo>

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
      *out << stamp;
      *out << " - ";
      *out << s << std::endl;
      return *this;
   }

   void Logger::setOutputFile(std::string filename)
   {
      out = new std::ofstream(filename.c_str());
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

   Logger::~Logger()
   {
      if (typeid(*out) == typeid(std::ofstream)) 
      {
         ((std::ofstream*)out)->close();
         delete out;
      }
   }
} /* namespace asteroids */
