#include <iostream>
#include "playlist.h"
#include "song.h"

Playlist::Playlist(int max_size) {
    playlist_size = max_size;
    playlist_arr = new Song[playlist_size];
    cout << "success" << endl;
}

Playlist::~Playlist() {
    delete [] playlist_arr;
}

int Playlist::addSong(string song_title, string song_artist){
    // if cannot insert the song, return -1
    for(int i = 0; i < playlist_size; i++) {

        if(playlist_arr[i].getSongTitle() == song_title
        && playlist_arr[i].getSongArtist() == song_artist) {
            return -1;
        }
        
        if(playlist_arr[i].getSongTitle() == ""
        && playlist_arr[i].getSongArtist() == "") {
            playlist_arr[i].setSongTitle(song_title);
            playlist_arr[i].setSongArtist(song_artist);
            return 0;
        }
    }
    return -1;
}

int Playlist::playXthSong(int n) {
    if (n > playlist_size) {
        return -1;
    }
    else if (playlist_arr[n-1].getSongTitle() != ""
    && playlist_arr[n-1].getSongArtist() != "") {
        string output_title = playlist_arr[n-1].getSongTitle();
        string output_artist = playlist_arr[n-1].getSongArtist();

        cout << "played " << n << ' ' << output_title << ';' << output_artist << endl;
        return 0;
    }
    return -1;
}

int Playlist::deleteXthSong(int n) {
    if (n > playlist_size) {
        return -1;
    }
    else if (playlist_arr[n-1].getSongTitle() != ""
    && playlist_arr[n-1].getSongArtist() != "") {

        for (int i = n-1; i<playlist_size; i++) {

            if (i == playlist_size - 1) {
                playlist_arr[i].setSongTitle("");
                playlist_arr[i].setSongArtist("");
            }

            else {
                playlist_arr[i].setSongTitle(playlist_arr[i+1].getSongTitle());
                playlist_arr[i].setSongArtist(playlist_arr[i+1].getSongArtist());
            }
        }

        return 0;
    }

    return -1;
}