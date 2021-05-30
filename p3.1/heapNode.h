#ifndef HNODE
#define HNODE

using namespace std;

class heapNode {
    private:
        int vertex;
        double key;

    public:
        heapNode(int vertex, double key);
        ~heapNode();

        int getVertex();
        void setKey(double k);
        double getKey();

};

#endif