// niaz hussain
// lab 6 – binary trees
// cst 202 – data structures

//node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

//stores a word and its occurrence count
class Node {
private:
    string word;
    int count;
    Node* left;     //pointer to left child
    Node* right;    //pointer to right child

public:
    Node(const string& w);
    ~Node();                 //destructor

    const string& getWord() const;   //get stored word
    int getCount() const;            //get count
    void incrementCount();           //increment count

    //print as "word : count"
    friend ostream& operator<<(ostream& os, const Node& n);
    friend class Tree;       //allow tree to access private members
};

#endif
