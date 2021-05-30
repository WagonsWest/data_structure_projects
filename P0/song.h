#ifndef SONG
#define SONG

using namespace std;

class Song 
{
private:
    string title;
    string artist;

public:
    Song();
    ~Song();

    void setSongTitle(string input_title);
    string getSongTitle();

    void setSongArtist(string input_artist);
    string getSongArtist();
};

#endif
