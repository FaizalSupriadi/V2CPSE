#include "hwlib.hpp"
#include "sin.hpp"
#include "clock.hpp"
#include <array>

int main( void ){	

   namespace target = hwlib::target; 

   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   auto tilt = target::pin_in( target::pins::d6 );
   auto sw = target::pin_in( target::pins::d5 );

   auto display = hwlib::glcd_oled{ i2c_bus, 0x3c };

   hwlib::wait_ms(100);
   
   constexpr hwlib::xy location = hwlib::xy( 64, 32 );
   int radius = 32;
   int sizeMarker = 3;
   int hour = 3;
   int minute = 59;
   int second = 50;
   constexpr auto sinus = lookup< 360, int >( scaled_sine_from_degrees );
   constexpr auto cosinus = lookup< 360, int >( scaled_cosine_from_degrees );
   tilt_sensor tiltSense( tilt );

   clock Clock = clock( display, tiltSense, sw, location, radius, sizeMarker, hour, minute, second, sinus, cosinus );

   unsigned int t = hwlib::now_us();

   for(;;){

      if( hwlib::now_us() >= (t + 810700) ){					//it takes around 189300 microseconds to update the clock
      	 Clock.updateTime();
         t = hwlib::now_us();
      }

      if(sw.read() == 0){
      	 Clock.changeTime();
      }
   }

}