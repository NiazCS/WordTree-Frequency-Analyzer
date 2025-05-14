// niaz hussain
// lab 6 – binary trees
// cst 202 – data structures

//tree.h
#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <fstream>
#include <string>
using namespace std;

//binary search tree for storing words and their counts
class Tree {
private:
    Node* root;        //root of the tree
    int uniqueCount;   //number of distinct words

    Node* insertRec(Node* n, const string& w); //recursive insert
    void inorderRec(Node* n, ofstream& out) const; //recursive in-order
    void deleteRec(Node* n); //recursive deletion
    int totalCountRec(Node* n) const; //sum of all counts

public:
    Tree();    //constructor
    ~Tree();   //destructor

    //insert or update word -> returns true if new word
    bool insert(const string& w);

    //write sorted words and summary to file
    void writeInOrder(const string& filename) const;

    int getUniqueCount() const; //get number of distinct words
};

#endif
