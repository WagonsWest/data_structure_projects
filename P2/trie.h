#ifndef TRIE
#define TRIE

#include "node.h"

class trie {
    private:
        int num_words;
        node* root;
        
    public:
        trie();
        ~trie();

        void insert_word(std::string input_word);
        node* erase(node* parent, std::string erase_word, int depth);
        void erase_word(std::string in_erase);
        bool search(std::string search_word);

        bool autocomplete(node* current, std::string prefix, bool is_first);
        void print_all();
        int print_auto(std::string in_prefix);

        int isEmpty(node* n);
        int isTempty();
        void clear();
        void size();
        
};

#endif