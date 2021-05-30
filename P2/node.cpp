#include <string>
#include "node.h"

node::node() {
    key = "";
    is_end = false;
    for(int i = 0; i<ALPHABET_SIZE; i++) {
        children[i] = NULL;
    }
}

node::~node() {

}
