#include <string>
#include "node.h"

node::node() {
    url_name = "";
    url = "";
    prev = NULL;
    next = NULL;
}

node::~node() {

}

node::node(std::string uname, std::string u) {
    url_name = uname;
    url = u;
}