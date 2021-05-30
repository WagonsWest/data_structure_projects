#ifndef GRAPH
#define GRAPH

#include "adList.h"
using namespace std;

class graph {
    private:
        int vertices;
        int edges;
        adList* adjacency_list;

    public:
        graph();
        ~graph();

        void create_graph(int num_n);
        void insert_edge(int u, int v, double w);
        void erase_edge(int u, int v);
        void adjacent(int u, int v, double w);
        void check_degree(int u);
        void edge_count();
        void clear();

        int size_nodes();

        void mstPrim(int u);
};

#endif