
#include <iostream>
#include "note_player_cout.hpp"

  
void note_player_cout::play( const note & n ){
      std::cout << "\nFreq: "<<n.frequency << "\nDur: "<<n.duration;
}