#include <iostream>
#include <string>
#include "deque.h"
#include "node.h"

using namespace std;

int main() {
    while(!(cin.eof())) {
        string command;
        deque hist;

        while(getline(cin, command)) {
            if (command.substr(0, 4) == "exit") {
                return 0;
            }

            else if(command.substr(0, 10) == "push_front") {
                string delimiter = "\"";
                int cursor = 0;

                int name_start = command.find(delimiter, cursor);
                cursor = name_start+1;
                int name_end = command.find(delimiter, cursor);
                cursor = name_end+1;
                string name = command.substr(name_start+1, name_end-name_start-1);

                int url_start = command.find(delimiter, cursor);
                cursor = url_start+1;
                int url_end = command.find(delimiter, cursor);
                string url = command.substr(url_start+1, url_end-url_start-1);

                hist.push_front(name, url);
            }
            else if(command.substr(0, 9) == "push_back") {
                string delimiter = "\"";
                int cursor = 0;

                int name_start = command.find(delimiter, cursor);
                cursor = name_start+1;
                int name_end = command.find(delimiter, cursor);
                cursor = name_end+1;
                string name = command.substr(name_start+1, name_end-name_start-1);

                int url_start = command.find(delimiter, cursor);
                cursor = url_start+1;
                int url_end = command.find(delimiter, cursor);
                string url = command.substr(url_start+1, url_end-url_start-1);

                hist.push_back(name, url);
            }
            else if(command.substr(0, 9) == "pop_front") {
                hist.pop_front();
            }
            else if(command.substr(0, 9) == "pop_back") {
                hist.pop_back();
            }
            else if(command.substr(0, 4) == "size") {
                hist.size();
            }
            else if(command.substr(0, 5) == "front") {
                hist.front();
            }
            else if(command.substr(0, 4) == "back") {
                hist.back();
            }
            else if(command.substr(0, 5) == "empty") {
                hist.empty();
            }
            else if(command.substr(0, 5) == "clear") {
                hist.clear();
            }
            else if(command.substr(0, 4) == "find") {
                string delimiter = "\"";
                size_t cursor = 0;

                int name_start = command.find(delimiter, cursor);
                cursor = name_start+1;
                int name_end = command.find(delimiter, cursor);
                string name = command.substr(name_start+1, name_end-name_start-1);

                hist.find(name);
            }
            else if(command.substr(0, 5) == "print") {
                hist.print();
            }
        }
    }
}