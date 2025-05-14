// niaz hussain
// lab 6 – binary trees
// cst 202 – data structures

//node.cpp
#include "Node.h"

//initialize with word and count=1 and null children
Node::Node(const string& w)
    : word(w), count(1), left(nullptr), right(nullptr) {
}

Node::~Node() {}

//return stored word
const string& Node::getWord() const {
    return word;
}

//return occurrence count
int Node::getCount() const {
    return count;
}

//increase count by 1
void Node::incrementCount() {
    ++count;
}

//print as "word : count"
ostream& operator<<(ostream& os, const Node& n) {
    os << n.word << " : " << n.count;
    return os;
}
