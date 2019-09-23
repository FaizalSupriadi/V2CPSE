#ifndef _NOTE_PLAYER_COUT_HPP
#define _NOTE_PLAYER_COUT_HPP

#include "note_player.hpp"

class note_player_cout : public note_player {
public: 
   void play( const note & n ) override;
};

#endif

