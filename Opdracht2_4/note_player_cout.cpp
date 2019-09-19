
#include <fstream>
#include <iostream>
#include "note_player_cout.hpp"

using namespace std;
void note_player_cout::play( const note & n ){
	ofstream myFile;
	myFile.open("melody.cpp", fstream::app);
	if(n.frequency !=0){
		if(myFile.is_open()){	
			myFile <<  "	p.play( note{ note::" << n.frequency << ",  note::" << n.duration << " } )\n";
			myFile.close();
		}
	}
}