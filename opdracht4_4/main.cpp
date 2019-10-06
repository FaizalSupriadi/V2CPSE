#include "hwlib.hpp"

extern "C" void print( const char c ){
	hwlib::cout << c;
}

extern "C" void decompress();

int main(){
	hwlib::wait_ms(500);
	decompress();

}