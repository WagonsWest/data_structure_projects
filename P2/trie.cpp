#include "trie.h"
#include <iostream>

trie::trie() {
    num_words = 0;
    root = new node();
}

trie::~trie() {

}

void trie::insert_word(std::string input_word) {
    node* temp = root;
    for(int i = 0; i<input_word.length(); i++) {

        int c_index = input_word[i] - 'a';

        if (!temp->children[c_index]) {
            temp->children[c_index] = new node();
        }

        temp = temp->children[c_index];
    }

    if (temp->is_end == true) {
        std::cout << "failure" << std::endl;

    } else {
        temp->is_end = true;
        num_words += 1;
        std::cout << "success" << std::endl;
    }
}

node* trie::erase(node *parent, std::string erase_word, int depth = 0) {
    if (!root)
        return NULL;
    
    if (depth == erase_word.size()) {
        if(parent->is_end)
            parent->is_end = false;

        if(isEmpty(parent)) {
            delete(parent);
            parent = NULL;
        }

        num_words -= 1;
        return parent;
    }

    //if not last char, do recurrence for the child
    int index = erase_word[depth] - 'a';
    parent->children[index] = erase(parent->children[index], erase_word, depth+1);

    if(isEmpty(parent) && parent->is_end == false) {
        delete(parent);
        parent = NULL;
    }
    return parent;
}

void trie::erase_word(std::string in_erase) {
    int num_words_preerase = num_words;
    erase(root, in_erase);
    if (num_words_preerase!=num_words) {
        std::cout<< "success"<<std::endl;
    } else {
        std::cout<< "failure"<<std::endl;
    }
}

bool trie::search(std::string search_word) {
    node* s_temp = root;
    for (int i=0; i<search_word.length(); i++) {
        int s_index = search_word[i] - 'a';

        if(!s_temp->children[s_index]) {
            return false;
        }
        s_temp = s_temp->children[s_index];
    }

    return (s_temp != NULL && s_temp->is_end);
}


bool trie::autocomplete(node* current, std::string prefix, bool is_first) {
    if(current->is_end) {
        if (!is_first)
            std::cout << " " << prefix;
        else {
            std::cout << prefix;
            is_first = false;
        }
    }

    if(isEmpty(current)) {
        return is_first;
    }

    for(int i=0; i<ALPHABET_SIZE; i++) {
        if(current->children[i]) {
            prefix.push_back(97+i);
            is_first = autocomplete(current->children[i], prefix, is_first);
            prefix.pop_back();
        }
    }
    return is_first;
}


int trie::print_auto(std::string in_prefix) {
    node* current_root = root;
    if(in_prefix.back() == '*')
        in_prefix.pop_back();
    
    int pre_len = in_prefix.length();
    int current_char;
    for (current_char = 0; current_char<pre_len; current_char++) {
        int index = in_prefix[current_char] - 'a';

        if(!current_root->children[index])
            return 0;

        current_root = current_root->children[index];
    }

    std::string pre = in_prefix;
    bool is_first = true;

    is_first = autocomplete(current_root, pre, is_first);
    if(!is_first)
        std::cout << std::endl;

    return 1;
}

void trie::print_all() {
    if(num_words!=0) {
        bool is_first = true;
        is_first = autocomplete(root, "", is_first);

        if(!is_first)
            std::cout << std::endl;
    }
}

int trie::isEmpty(node* n) {
    for (int i=0; i<ALPHABET_SIZE; i++) {
        if(n->children[i]) {
            return 0;
        }
    }
    return 1;
}

int trie::isTempty() {
    return isEmpty(root);
}

void trie::clear() {
    if(isEmpty(root))
        std::cout << "success" << std::endl;
    else {
        for (int i=0; i<ALPHABET_SIZE; i++) {
            if (root->children[i]) {
                root->children[i] = NULL;
            }
        }
        std::cout << "success" << std::endl;
    }
}

void trie::size() {
    std::cout << "number of words is " << num_words << std::endl;
}