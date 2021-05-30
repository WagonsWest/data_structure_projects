#ifndef NODE
#define NODE

using namespace std;

class alNode {
    private:
        int vertex;
        double weight;
        alNode* next_node;

    public:
        alNode(const int v, const double weight);
        ~alNode();

        void setNext(alNode* nxt);
        alNode* getNext();
        int getVertex();
        double getWeight();

};

#endif