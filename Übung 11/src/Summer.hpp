/**
 * @file Summer.hpp
 * @author rdiederichse@uos.de
 * @brief Contains a unary_function struct definition to sum int vector elements.
 */
#ifndef SUMMER_H
#define SUMMER_H

#include <functional>

struct Summer : public std::unary_function<int,int>
{
   Summer() : sum(0) {}
   void operator()(int i)
   {
      sum += i;
   }
   int sum;
};

#endif /* end of include guard: SUMMER_H */
