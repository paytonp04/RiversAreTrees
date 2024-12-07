#include "header.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;

// Constructor
BinaryTree::BinaryTree() : root(nullptr) {}

// Destructor
BinaryTree::~BinaryTree() {
    destroyTree(root);
}

// Helper function to destroy tree
void BinaryTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Insert function 
void BinaryTree::insert(int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        root = newNode;
    } else {
        Node* current = root;
        Node* parent = nullptr;
        while (true) {
            parent = current;
            if (value < current->data) {
                current = current->left;
                if (current == nullptr) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == nullptr) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

// Move to the right child
Node* BinaryTree::moveToRightChild(Node* node) {
    if (node != nullptr && node->right != nullptr) {
        return node->right;
    } else {
        return nullptr; // Return null if no right child exists
    }
}

// Print node information
void BinaryTree::printNodeInfo(Node* node) {
    if (node != nullptr) {
        std::cout << "Node data: " << node->data << std::endl;
    } else {
        std::cout << "Node is null." << std::endl;
    }
}