#include <iostream>

int main ( int argc, char **argv ){
	std::cout << "#include \"melody.hpp\"\n" << 
		 "void play( note_player & p ){\n" << argv[1];
	//for(;;){
	//	if(argv[1] == ""){break;}
		std::cout<<"p.play( note{ note::"<<argv[1]<<",  note::"<<argv[2]<<" )\n}\n";
	//}
}