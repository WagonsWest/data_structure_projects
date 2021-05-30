#ifndef NODE
#define NODE

#include <string>
const int ALPHABET_SIZE = 26;

class node
{
private:
    /* data */
    std::string key;
    node *children[ALPHABET_SIZE];
    bool is_end;

    friend class trie;

public:
    node(/* args */);
    ~node();
    
};

#endif
