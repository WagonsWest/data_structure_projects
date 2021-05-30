#include <iostream>
#include <string>
#include "song.h"
#include "playlist.h"

using namespace std;

int main(){
    while(!(cin.eof())) {
        string command;
        getline(cin, command);

        if (command.substr(0, 1) == "m") {
            const int size = stoi(command.substr(2, 1));
            Playlist plylst(size);
        
            while(getline(cin, command)) {

                if (command.substr(0, 4) == "exit") {
                    return 0;
                }

                else if (command.substr(0, 1) == "i") {
                    string title = command.substr(2, command.find(";") - 2);
                    string artist = command.substr(command.find(";")+1);
                    
                    if (plylst.addSong(title, artist) == 0) {
                        cout << "success" << endl;
                    }
                    else {
                        cout << "can not insert " << title << ";" << artist << endl;
                    }
                }

                else if (command.substr(0, 1) == "p") {
                    int pos = stoi(command.substr(2, 1));
                    if(plylst.playXthSong(pos) == -1) {
                        cout << "can not play " << pos << endl;
                    }
                }

                else if (command.substr(0, 1) == "e") {
                    int del = stoi(command.substr(2, 1));
                    if(plylst.deleteXthSong(del) == 0) {
                        cout << "success" << endl;
                    }
                    else {
                        cout << "can not erase " << del << endl;
                    }
                }

            }
        }

        

    
    }
}