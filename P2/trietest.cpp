#include <iostream>
#include <string>
#include "trie.h"
#include "node.h"

using namespace std;

struct illegal_exception : public std::exception {
   const char * what () const throw () {
      return "illegal argument";
   }
};

int main() {
    while(!(cin.eof())) {
        string command;
        trie tds;

        while(getline(cin, command)) {
            if(command.substr(0, 4) == "exit") {
                return 0;
            }

            else if(command.substr(0, 1) == "i") {
                string input = command.substr(2);
                try {
                    for(int i = 0; i<input.length(); i++){
                        int index = input[i] - 'a';
                        if (0>index || 25<index) {
                            throw illegal_exception();
                        }
                    }
                    tds.insert_word(input);
                }
                catch(std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(command.substr(0, 1) == "e" && command.substr(0, 5) != "empty") {
                string input = command.substr(2);
                try {
                    for(int i = 0; i<input.length(); i++){
                        int index = input[i] - 'a';
                        if (0>index || 25<index) {
                            throw illegal_exception();
                        }
                    }
                    tds.erase_word(input);
                }
                catch(std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(command.substr(0, 1) == "s" && command.substr(0, 4) != "size") {
                string input = command.substr(2);
                try {
                    for(int i = 0; i<input.length(); i++){
                        int index = input[i] - 'a';
                        if (0>index || 25<index) {
                            throw illegal_exception();
                        }
                    }

                    if (tds.search(input)) {
                        cout << "found " << input << endl;
                    } else if (!tds.search(input)){
                        cout << "not found" << endl;
                    }
                }
                catch(std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }

            else if(command.substr(0, 5) == "print") {
                tds.print_all();
            }

            else if(command.substr(0, 12) == "autocomplete") {
                string input = command.substr(13);
                tds.print_auto(input);
            }

            else if(command.substr(0, 5) == "empty") {
                cout << "empty " << tds.isTempty() << endl;
            }

            else if(command.substr(0, 5) == "clear") {
                tds.clear();
            }

            else if(command.substr(0, 4) == "size") {
                tds.size();
            }
        }
    }
}