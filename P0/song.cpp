#include <string>
#include "song.h"

Song::Song(){
    title = "";
    artist = "";
}

Song::~Song(){
    
}

void Song::setSongTitle(string input_title){
    title = input_title;
}

string Song::getSongTitle() {
    return title;
}

void Song::setSongArtist(string input_artist){
    artist = input_artist;
}

string Song::getSongArtist(){
    return artist;
}