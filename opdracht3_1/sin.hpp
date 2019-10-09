#ifndef _SIN_HPP
#define _SIN_HPP

#include "hwlib.hpp"
#include <math.h>

   
constexpr double pow( double g, int n ){
   double result = 1;
   while( n > 0 ){
       result *= g;
       --n;
   }
   return result;
}

constexpr double fac( int n ){
   double result = 1;
   while( n > 0 ){
       result *= n;
       --n;
   }
   return result;
}

constexpr double sin( double a ){
   return 
      a 
      - pow( a, 3 ) / fac( 3 ) 
      + pow( a, 5 ) / fac( 5 ) 
      - pow( a, 7 ) / fac( 7 )
      + pow( a, 9 ) / fac( 9 ) 
      - pow( a, 11 ) / fac( 11 ) 
      + pow( a, 13 ) / fac( 13 );
}
constexpr double radians_from_degrees( int degrees ){
    return 2 * 3.14 * ( degrees / 360.0 );
}

constexpr int scaled_sine_from_degrees( int degrees ){
    return 64 + ( 30 * sin( radians_from_degrees(degrees) ));
}

constexpr int scaled_cosine_from_degrees( int degrees ){
    return 32 + (30 * sin( radians_from_degrees(degrees - 90 )));
}

#endif //_SIN_HPP