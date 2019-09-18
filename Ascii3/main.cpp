#include "hwlib.hpp"

extern "C" void print_asciz( const char * s );

extern "C" void uart_put_char( char c ){
	hwlib::cout << c;
}

extern "C" void application();

extern "C" char convert( char l ){
 	if( l > 64 && l < 91){
		l+=32;
	}else if( l > 96 && l < 123 ){
	  	l-=32;
	}
	return l;
}

int main(){
    namespace target = hwlib::target;
	hwlib::wait_ms( 2000 );
	application();
}