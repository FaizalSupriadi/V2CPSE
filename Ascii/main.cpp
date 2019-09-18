#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
	hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

void application(){
	print_asciz( "Hello world\n" );
}
int main(){
    namespace target = hwlib::target;
	hwlib::wait_ms( 2000 );
	application();
}