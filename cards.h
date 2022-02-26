//cards.h
//Authors: Ethan Neill
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
using namespace std;

class IntBST {

 public:
    // ctor, dtor, insert and one print method already done in intbst.cpp:
    IntBST();                   // constructor
    ~IntBST();                  // destructor
    bool insert(int value, string card);     // insert value; return false if duplicate
    void printPreOrder() const; // prints tree data pre-order to cout

    // 8 METHODS YOU MUST IMPLEMENT in intbst.cpp:
    void printInOrder() const;       // print tree data in-order to cout
    void printPostOrder() const;     // print tree data post-order to cout
    bool contains(int value) const;  // true if value is in tree
    int getSmallest() const;
    int getLargest() const;
    void printCard(int value) const;

    // THESE ARE HARDER! DO THESE LAST
    int getPredecessor(int value) const;       // returns the predecessor value of the given value or 0 if there is none
    int getSuccessor(int value) const;         // returns the successor value of the given value or 0 if there is none
    void remove(int value);                    // deletes the Node containing the given value from the tree

 private:

    struct Node {
	int info;
    string card;
	Node *left, *right, * parent;
	// useful constructor:
    Node(int v=0, string y=0) : info(v), card(y), left(0), right(0), parent(0) { }
    };

    // just one instance variable (pointer to root node):
    Node *root;

    // recursive utility functions for use by public methods above
    Node* getNodeFor(int value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(int value, Node *n, string card); // note overloading names for simplicity
    void printPreOrder(Node *n) const;
    void printInOrder(Node *n) const;
    void printPostOrder(Node *n) const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(int value) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(int value) const; // returns the Node containing the predecessor of the given value 
};

#endif