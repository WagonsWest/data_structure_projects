#ifndef NODE
#define NODE

class node {
    private:
        std::string url_name;
        std::string url;
        node *prev;
        node *next;

        friend class deque;

    public:
        node();
        ~node();

        node(std::string uname, std::string u);

};

#endif