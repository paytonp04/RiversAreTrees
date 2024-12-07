#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <string>
#include <vector>


using namespace std;

// Constructor
BinaryTree::BinaryTree() : root(nullptr) {}

// Destructor
BinaryTree::~BinaryTree() {
    destroyTree(root);
}

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree(); // Constructor
    ~BinaryTree(); // Destructor

    void insert(int value); 
    Node* moveToRightChild(Node* node); 
    void printNodeInfo(Node* node); 
private:
    void destroyTree(Node* node); 
};

#endif