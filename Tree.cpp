// niaz hussain
// lab 6 – binary trees
// cst 202 – data structures

//tree.cpp
#include "Tree.h"
#include <iostream>

//constructor initializes empty tree
Tree::Tree()
    : root(nullptr), uniqueCount(0) {
}

//destructor deletes all nodes
Tree::~Tree() {
    deleteRec(root);
}

//if word exists, increment, else create new node
Node* Tree::insertRec(Node* n, const string& w) {
    if (!n) {
        ++uniqueCount;
        return new Node(w);
    }
    if (w == n->word) {
        n->incrementCount();
    }
    else if (w < n->word) {
        n->left = insertRec(n->left, w);
    }
    else {
        n->right = insertRec(n->right, w);
    }
    return n;
}

//wraps recursive insert
bool Tree::insert(const string& w) {
    int before = uniqueCount;
    root = insertRec(root, w);
    return uniqueCount > before;
}

//print in-order traversal to file
void Tree::inorderRec(Node* n, ofstream& out) const {
    if (!n) return;
    inorderRec(n->left, out);
    out << *n << "\n";
    inorderRec(n->right, out);
}

//recursive sum of all word counts
int Tree::totalCountRec(Node* n) const {
    if (!n) return 0;
    return n->count + totalCountRec(n->left) + totalCountRec(n->right);
}

//ofst sorted words and totals to file
void Tree::writeInOrder(const string& filename) const {
    ofstream out(filename.c_str());
    if (!out.is_open()) {
        cerr << "can't open " << filename << " for writing\n";
        return;
    }
    inorderRec(root, out);
    out << "\n";
    out << "total unique words: " << uniqueCount << "\n";
    int total = totalCountRec(root);
    out << "total words: " << total << "\n";
    out.close();
}

//recursive deletion post-order
void Tree::deleteRec(Node* n) {
    if (!n) return;
    deleteRec(n->left);
    deleteRec(n->right);
    delete n;
}

//return number of distinct words
int Tree::getUniqueCount() const {
    return uniqueCount;
}
