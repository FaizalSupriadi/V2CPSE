#include "clock.hpp"

clock::clock( hwlib::glcd_oled & oled, tilt_sensor & tilt, hwlib::pin_in & sw, hwlib::xy location, int & radius, int & sizeMarkers, int & hour, int & minute, int & second, lookup<360, int> sinus, lookup<360, int> cosinus ):
   oled( oled ),
   tilt( tilt ),
   sw( sw ),
   location( location ),
   radius( radius ),
   sizeMarkers( sizeMarkers ),
   hour( hour ),
   minute( minute ),
   second( second ),
   sinus( sinus ),
   cosinus( cosinus )
{
   oled.clear();
}

void clock::hourMarkers( hwlib::xy location, int radius, int sizeMarkers ){
	hwlib::circle( location, radius ).draw( oled );

	for( int i = 0; i < 360; i+=30 ){
       int x = sinus.get( i );
       int y = cosinus.get( i );

       hwlib::circle( hwlib::xy( x, y ), sizeMarkers ).draw( oled );
   }
}
void clock::drawHourHand( hwlib::xy location ){
	int x = sinus.get( hour * 30 );									//times 30, because it needs to be in degrees, and /2 to make the clock hand shorter
    int y = cosinus.get( hour * 30 );								

	hwlib::line( location, hwlib::xy( x, y ) ).draw( oled );
}

void clock::drawminuteHand( hwlib::xy location ){
	int x = sinus.get( minute * 6 );									
    int y = cosinus.get( minute * 6 );									

	hwlib::line( location, hwlib::xy( x, y ) ).draw( oled );
}

void clock::drawSecondHand( hwlib::xy location ){
    int x = sinus.get( second * 6 );									
    int y = cosinus.get( second * 6 );									

	hwlib::line( location, hwlib::xy( x, y ) ).draw( oled );
}

void clock::drawClock(){
	oled.clear();
	hourMarkers( location, radius, sizeMarkers );
	drawHourHand( location );
	drawminuteHand( location );
	drawSecondHand( location );
	oled.flush();
}

void clock::updateTime(){

	if( second == 59 ){
		second = 0;
		if( minute == 59 ){
			minute = 0;
			if(hour == 11){
				hour = 0;
			}else{
				hour++;
			}
		}else{
			minute++;
		}
	}else{
		second++;
	}

	drawClock();
}

void clock::changeTime(){
	int counter=0;

	for(;;){           												
   	  //hwlib::wait_ms(100);														
		
		drawClock();

		for(;;){													

			if(sw.read() == 0){											
				counter++; 
				break;  	  		    											
			}

			if( tilt.get() == 1){						
				if(counter == 1){
					if(hour == 11){
						hour = 0;
					}else{
						hour++;
					}
				}else if(counter == 2){
					if(minute == 59){
						minute = 0;
					}else{
						minute++;
					}
				}else{
					if(second == 59){
						second = 0;
					}else{
						second++;
					}
				}											
				break;												
			}else if(tilt.get() == 0){			
				if(counter == 1){
					if(hour == 0){
						hour = 11;
					}else{
						hour--;
					}
				}else if(counter == 2){
					if(minute == 0){
						minute = 59;
					}else{
						minute--;
					}
				}else{
					if(second == 0){
						second = 59;
					}else{
						second--;
					}
				}												

				break;													
			}else if(tilt.get() == 0){				
				break;													
			}					
		}
		
		if( counter > 2 ){
			break;
		}
	}

}