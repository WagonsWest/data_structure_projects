#ifndef PLAYLIST
#define PLAYLIST

#include "song.h"

using namespace std;

class Playlist
{
private:
    /* data */
    int playlist_size;
    Song *playlist_arr;

public:
    Playlist(int max_size);
    ~Playlist();

    int addSong(string song_title, string song_artist);
    int playXthSong(int n);
    int deleteXthSong(int n);

};

#endif