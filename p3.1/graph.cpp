#include "graph.h"
#include "heap.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

const double INF = 2^31-1;

graph::graph() {
    vertices = 0;
    edges = 0;
    adjacency_list = NULL;
}

graph::~graph() {

}

void graph::create_graph(int num_n) {
    vertices = num_n;
    adjacency_list = new adList[vertices];

    cout << "success" << endl;
}

void graph::insert_edge(int u, int v, double w) {
    //add two edges
    if(adjacency_list[u].erase(v)) {
        adjacency_list[v].erase(u);
        
    } else {
        edges += 2;
    }

    alNode* new_u = new alNode(v, w);
    new_u->setNext(adjacency_list[u].getHead());
    adjacency_list[u].setHead(new_u);

    alNode* new_v = new alNode(u, w);
    new_v->setNext(adjacency_list[v].getHead());
    adjacency_list[v].setHead(new_v);

    cout << "success" << endl;
}

void graph::erase_edge(int u, int v) {
    if(adjacency_list[u].erase(v)) {
        adjacency_list[v].erase(u);
        edges -= 2;
        cout << "success" << endl;
    } else {
        cout << "failure" << endl;
    }
}

void graph::adjacent(int u, int v, double w) {
    if(adjacency_list[u].adjacent_withE(v, w)) {
        cout << "adjacent " << u << " " << v << " " << fixed << setprecision(2) << w << endl;
    } else {
        cout << "not adjacent " << u << " " << v << " " << fixed << setprecision(2) << w << endl;
    }
}

void graph::check_degree(int u) {
    cout << "degree of " << u << " is " << adjacency_list[u].getDegree() << endl;
}

void graph::edge_count() {
    cout << "edge count is " << edges << endl;
}

void graph::clear() {
    for(int i = 0; i<vertices; i++) {
        adjacency_list[i].setHead(NULL);
    }
    edges = 0;
    cout << "success" << endl;
}

void graph::mstPrim(int u) {
    vector<int> mst_list;
    double* key_list = new double[vertices];

    heap* bi_heap = new heap(vertices);
    double total_weight = 0;

    for(int i=0; i<vertices; i++)
        key_list[i] = INF;
    key_list[u] = 0;

    for(int i=0; i<vertices; i++) {
        bi_heap->insertNode(i, key_list[i]);
        bi_heap->setPosition(i);
    }

    bi_heap->setSize(vertices);

    if(u!=0) {
        int temp_u = u;
        int counter = 0;
        while(temp_u!=0) {
            temp_u = (temp_u-1)/2;
            counter += 1;
        }
        for(int i=0; i<counter; i++) {
            bi_heap->heapify((u-1)/2);
            u = (u-1)/2;
        }
    }

    while(bi_heap->getSize() != 0) {
        heapNode* extract_node = bi_heap->extractMin();
        mst_list.push_back(extract_node->getVertex());
        //cout << extract_node->getVertex() << endl;

        if(extract_node->getKey()==INF) {
            break;
        }
        total_weight += extract_node->getKey();

        int vertex = extract_node->getVertex();
        alNode* neighbor = adjacency_list[vertex].getHead();

        while (neighbor !=NULL) {
            int v = neighbor->getVertex();
            if(bi_heap->inHeap(v)&&neighbor->getWeight()<key_list[v]) {
                key_list[v] = neighbor->getWeight();
                bi_heap->modifyKey(v, key_list[v]);
            }
            //cout << key_list[v] << v << endl;
            neighbor = neighbor->getNext();
        }
        //cout << bi_heap->getSize() << endl;
    }

    if(mst_list.size()<vertices) {
        cout << "not connected" << endl;
        
    } else {
        cout << "mst " << fixed << setprecision(2) << total_weight << endl;
    
    }
    bi_heap->~heap();
    delete[] key_list;
    /*for(int i=0; i<mst_list.size(); i++)
        cout << mst_list[i];
    cout << endl;
    cout << mst_list.size() << endl;*/

}

int graph::size_nodes() {
    return vertices;
}