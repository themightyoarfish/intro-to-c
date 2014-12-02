/**
 * @file ReadPPM.cpp
 * @author Rasmus Diederichsen (rdiederichse@uos.de)
 * @version 02.12.2014
 */

#include "ReadPPM.hpp"
#include <sstream>
#include <iostream>

using namespace std;

 namespace asteroids 
 {
    ReadPPM::ReadPPM(const std::string& filename) 
    {
       m_pixels = NULL;
       m_height = m_width = 0;
       ifstream file(filename.c_str());

       if (file.good()) 
       {
          const int bufsize = 100;
          char buffer[bufsize];
          readline(file, buffer, bufsize);
          string magic_number(buffer);
          if (magic_number == "P3") 
          {
             readline(file, buffer, bufsize);
             string line(buffer);
             stringstream ss(line);
             ss >> m_width >> m_height; 
             readline(file, buffer, bufsize);

             m_pixels = new unsigned char[m_width * m_height * 3];

             for(int i = 0; i < m_width * m_height * 3; i++) file >> m_pixels[i];

          } else 
          {
             cerr << "Error. Can only read ascii ppm file." << endl;
          }
       }
    }

    ReadPPM::~ReadPPM() { }

    void ReadPPM::readline(ifstream& stream, char* buffer, const int bufsize)
    {
       for (stream.getline(buffer, bufsize) ; stream.good() && buffer[0] == '#'; );
    }

 } /* namespace asteroids */
