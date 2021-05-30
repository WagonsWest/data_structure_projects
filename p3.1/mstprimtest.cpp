#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

struct illegal_exception : public exception {
    const char * what () const throw () {
        return "illegal argument";
    }
};

int main() {
    while(!(cin.eof())) {
        string command;
        graph prim;

        while(getline(cin, command)) {
            if(command.substr(0, 4) == "exit") {
                return 0;
            }

            else if(command.substr(0, 8) == "adjacent") {
                try {
                    string delimiter = ";";
                    int cursor = 0;

                    int su_end = command.find(delimiter, cursor);
                    string su = command.substr(9, su_end-9);
                    cursor = su_end+1;
                    int sv_end = command.find(delimiter, cursor);
                    string sv = command.substr(cursor, sv_end-cursor);
                    cursor = sv_end+1;
                    string sw = command.substr(cursor);

                    int u_node = stoi(su);
                    int v_node = stoi(sv);
                    double uv_weight = stof(sw);

                    if(u_node>=prim.size_nodes() || v_node>=prim.size_nodes()
                    || u_node == v_node) {
                        throw illegal_exception();
                    }
                    prim.adjacent(u_node, v_node, uv_weight);
                }
                catch(exception& e) {
                    cout << e.what() << endl;
                }
            }

            else if(command.substr(0, 6) == "degree") {
                string su = command.substr(7);
                int u_node = stoi(su);
                try {
                    if(u_node>=prim.size_nodes()) {
                        throw illegal_exception();
                    }
                    prim.check_degree(u_node);
                }
                catch(exception& e) {
                    cout << e.what() << endl;
                }
            }

            else if(command.substr(0, 10) == "edge_count") {
                prim.edge_count();
            }

            else if(command.substr(0, 5) == "clear") {
                prim.clear();
            }

            else if(command.substr(0, 1) == "n") {
                string sm = command.substr(2);
                int m = stoi(sm);
                prim.create_graph(m);
            }

            else if(command.substr(0, 1) == "i") {
                string delimiter = ";";
                int cursor = 0;

                int su_end = command.find(delimiter, cursor);
                string su = command.substr(2, su_end-2);
                cursor = su_end+1;
                int sv_end = command.find(delimiter, cursor);
                string sv = command.substr(cursor, sv_end-cursor);
                cursor = sv_end+1;
                string sw = command.substr(cursor);

                int u_node = stoi(su);
                int v_node = stoi(sv);
                double uv_weight = stof(sw);

                try {
                    if(u_node>=prim.size_nodes() || v_node>=prim.size_nodes()
                    || u_node == v_node || uv_weight<=0) {
                        throw illegal_exception();
                    }
                    prim.insert_edge(u_node, v_node, uv_weight);
                }
                catch(exception& e) {
                    cout << e.what() << endl;
                }
            }

            else if(command.substr(0, 1) == "e") {
                string delimiter = ";";
                int cursor = 0;

                int su_end = command.find(delimiter, cursor);
                string su = command.substr(2, su_end-2);
                cursor = su_end+1;
                int sv_end = command.find(delimiter, cursor);
                string sv = command.substr(cursor, sv_end-cursor);

                int u_node = stoi(su);
                int v_node = stoi(sv);

                try {
                    if(u_node>=prim.size_nodes() || v_node>=prim.size_nodes()
                    || u_node == v_node) {
                        throw illegal_exception();
                    }
                    prim.erase_edge(u_node, v_node);
                }
                catch(exception& e) {
                    cout << e.what() << endl;
                }
            }

            else if(command.substr(0, 3) == "mst") {
                string su = command.substr(4);
                int u_node = stoi(su);
                try {
                    if(u_node>=prim.size_nodes()) {
                        throw illegal_exception();
                    }
                    prim.mstPrim(u_node);
                }
                catch(exception& e) {
                    cout << e.what() << endl;
                }
            }
        }
    }
}