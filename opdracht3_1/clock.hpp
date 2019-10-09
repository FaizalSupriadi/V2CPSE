#ifndef _CLOCK_HPP
#define _CLOCK_HPP
#include "hwlib.hpp"
#include "sin.hpp"
#include <array>

template< int N, typename T >
class lookup {
private:    
   std::array< T, N > values = {};

public: 

   template< typename F >
   constexpr lookup( F function ){
      for( int i = 0; i < N; i+=6 ){                     //6 omdat 360/60 = 6
		  values[i] = function(i);
      }
   }

   constexpr T get( int n ) const {
      return values[ n ];    
   }
};

class clock{
private:

   hwlib::glcd_oled & oled;                  //the oled 
   hwlib::pin_in & sw;
   hwlib::xy location;                       //the middle point of the clock
   int radius;                               //the radius of the hole clock
   int sizeMarkers;                          //the size of the hour markings (the radius)
   int hour;                                 //the current hour (will be automatically 0)
   int minute;                                //the current minute (will be automatically 0)
   int second;

   const lookup< 360, int > sinus;           //the table of all the x-as values
   const lookup< 360, int > cosinus;         //the table of all the y-as values

public:

   //clock();
   clock( hwlib::glcd_oled & oled, hwlib::pin_in & sw, hwlib::xy location, int & radius, int & sizeMarkers, int & hour, int & minute, int & second, lookup<360, int> sinus, lookup<360, int> cosinus );

   void hourMarkers( hwlib::xy location, int radius, int sizeMarkers );
   void drawHourHand( hwlib::xy location );
   void drawminuteHand( hwlib::xy location );
   void drawSecondHand( hwlib::xy location );
   void drawClock();
   void updateTime();
   void changeTime();

};

#endif //_CLOCK_HPP