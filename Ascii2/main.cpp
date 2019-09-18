#include "hwlib.hpp"

extern "C" void print_asciz( const char * s );

extern "C" void uart_put_char( char c ){
	hwlib::cout << c;
}



extern "C" void application();

int main(){
    namespace target = hwlib::target;
	hwlib::wait_ms( 2000 );
	application();
}