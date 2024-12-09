/*
Name: Group 13
Class: CPSC223, Fall 2024
Date: December 8, 2024
Programming Assignment: Project 2
Description: 
*/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#endif

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Represents a dam with attributes for its size and year of construction
class Dam {
public:
    string name;     // Name of the dam
    int size;             // Size of the dam (e.g., capacity in cubic feet)
    int yearBuilt;        // Year the dam was constructed

    // Constructor to initialize a dam
    Dam(const string& n, int s, int y) 
        : name(n), size(s), yearBuilt(y) {}

    // Displays information about the dam
    void displayInfo() const {
        cout << "Dam Name: " << name 
                  << ", Size: " << size 
                  << ", Year Built: " << yearBuilt << "\n";
    }
};

// Represents a node in the binary tree, storing information about a water body
struct TreeNode {
    string name;          // Name of the water body (e.g., "Columbia River")
    string type;          // Type of the water body ("River", "Lake", "Stream")
    float flowRate;       // Float of average flow rate in river
    vector<Dam> dams;     // Vector to store dams associated with this water body
    TreeNode* left;            // Pointer to the left child node
    TreeNode* right;           // Pointer to the right child node

    // Constructor to initialize a tree node
    TreeNode(const string& n, const string& t, const float& f) 
        : name(n), type(t), flowRate(f), left(nullptr), right(nullptr) {}

    // Adds a dam to the vector of dams
    void addDam(const Dam& dam) {
        dams.push_back(dam);
    }

    // Displays information about the node and its associated dams
    void displayNode() const {
        cout << "Water Body: " << name << " (" << type << ")\n";
        for (const auto& dam : dams) {
            dam.displayInfo();
        }
    }
};


// Inserts a new node into the binary tree based on the parent water body
TreeNode* insertNode(TreeNode* root, const string& parent, 
                     const string& name, const float& flowRate, const string& type) {
    if (root == nullptr) {
        // Create a new node if the tree or subtree is empty
        return new TreeNode(name, type, flowRate);
    }

    if (root->name == parent) {
        // Check if the current node matches the parent
        if (!root->left) {
            root->left = new TreeNode(name, type, flowRate);  // Add as the left child if empty
        } else if (!root->right) {
            root->right = new TreeNode(name, type, flowRate); // Add as the right child if empty
        } else {
            // If both children exist, print a warning
            cout << "Parent node already has two children.\n";
        }
    } else {
        // Recursively traverse left and right subtrees to find the parent
        root->left = insertNode(root->left, parent, name, flowRate, type);
        root->right = insertNode(root->right, parent, name, flowRate, type);
    }

    return root; // Return the root of the updated tree
}
