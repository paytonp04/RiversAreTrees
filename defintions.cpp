#include "header.h"
#include <iostream>
using namespace std;

// Constructor for RiverNode
RiverNode::RiverNode(string riverName, RiverNode* parentNode) {
    name = riverName;
    left = nullptr;
    right = nullptr;
    parent = parentNode;
}

// Function to create a new node
RiverNode* createNode(string name, RiverNode* parent) {
    return new RiverNode(name, parent);
}

// Insert a node dynamically into the tree 
void insertNode(RiverNode* current, string direction, string riverName) {
    if (direction == "left") {
        // left insert
    } else if (direction == "right") {
        // right insert
    } else {
        cout << "Invalid direction. Use 'left' or 'right'." << endl;
    }
}

// Print tree information 
void printTree(RiverNode* node, int depth = 0) {
    
}

