//cards.cpp
//Authors: Ethan Neill
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
#include <string>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value, string card) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value, card);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root, card);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n, string card) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	    if (n->left)
	        return insert(value, n->left, card);
	    else {
	        n->left = new Node(value, card);
	        n->left->parent = n;
	        return true;
	    }
    }
    else {
	if (n->right)
	    return insert(value, n->right, card);
	else {
	    n->right = new Node(value, card);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if(n){
        printInOrder(n->left);
        cout<<n->card<<endl;
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if(n){
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout<<n->info<<" ";
    }
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n){
        if(n->info == value){
            return n;
        }
        else if(n->info >= value){
            getNodeFor(value, n->left);
        }
        else if(n->info <= value){
            getNodeFor(value, n->right);
        }
    }
    else{
        return nullptr;
    }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root) != nullptr){
        return true;
    }
    else{
        return false;
    }
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* current = getNodeFor(value, root);
    Node* pred = nullptr;
    Node* n = root;
    while(n->left){
        n = n->left;
    }
    if(n->info == value){
        return pred;
    }
    if(current->left){
        current = current->left;
        pred = current;
        while(current->right){
            current = current->right;
            pred = current;
        }
    }
    else if(current->parent){
        while(current->info < current->parent->info && current->parent){
            current = current->parent;
            pred = current;
        }
        pred = current->parent;
    }
    return pred;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if(getPredecessorNode(value)){
        return getPredecessorNode(value)->info;
    }
    else{
        return 0;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* current = getNodeFor(value, root);
    Node* succ = nullptr;
    Node* n = root;
    while(n->right){
        n = n->right;
    }
    if(n->info == value){
        return succ;
    }
    if(current->right){
        current = current->right;
        succ = current;
        while(current->left){
            current = current->left;
            succ = current;
        }
    }
    else if(current->parent){
        while((current->info > current->parent->info) && (current->parent)){
            current = current->parent;
            succ = current;
        }
        succ = current->parent;
    }
    return succ;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* result = getSuccessorNode(value);
    if(result){
        return result->info;
    }
    else{
        return 0;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    if(contains(value)){
        Node* current = getNodeFor(value, root);
        Node* succ = nullptr;
        if(current->left == nullptr && current->right == nullptr){
            if(current == root){
                delete root;
                root = nullptr;
            }
            else{
                if(current->info < current->parent->info){
                    current->parent->left = nullptr;
                }
                else{
                    current->parent->right = nullptr;
                }
                delete current;
            }
        }
        else if(current->left && current->right){
            succ = getSuccessorNode(current->info);
            int succValue = succ->info;
            string succCard = succ->card;
            remove(succ->info);
            current->info = succValue;
            current->card = succCard;
            root = current;
        }
        else if(current->left || current->right){
            if(current == root){
                if(current->left){
                    root = current->left;
                }
                else{
                    root = current->right;
                }
                delete current;
            }
            else{
                Node* child = current->left;
                if(current->right != nullptr){
                    child = current->right;
                }
                if(current->parent->left == current){
                    current->parent->left = child;
                }
                if(current->parent->right == current){
                    current->parent->right = child;
                }
                delete current;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

int IntBST::getSmallest() const{
    Node* n = root;
    while(n->left){
        n = n->left;
    }
    return n->info;
}

int IntBST::getLargest() const{
    Node* n = root;
    while(n->right){
        n = n->right;
    }
    return n->info;
}

void IntBST::printCard(int value) const{
    Node* n = getNodeFor(value, root);
    cout<<n->card;
}
