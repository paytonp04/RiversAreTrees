#include <iostream>
#include <string>
#include <vector>
#include "header.hpp"  // Include the header file

using namespace std;

int main() {
    // Create the root node of the binary tree
    TreeNode* root = new TreeNode("Columbia River", "River", 5000.0);

    // Insert child nodes representing water bodies
    root = insertNode(root, "Columbia River", "Snake River", 2500.0, "River");
    root = insertNode(root, "Columbia River", "Willamette River", 1500.0, "River");
    root = insertNode(root, "Snake River", "Salmon River", 200.0, "River");

    // Add dams to specific nodes
    root->addDam(Dam("Grand Coulee Dam", 5000000, 1942));
    if (root->left) {
        root->left->addDam(Dam("Lower Granite Dam", 3000000, 1975));
    }
    if (root->right) {
        root->right->addDam(Dam("Bonneville Dam", 1000000, 1938));
    }

    // Traverse and print nodes
    printNode(root);             // Print root node
    printNode(root->left);       // Print left child (Snake River)
    printNode(root->right);      // Print right child (Willamette River)
    if (root->left) {
        printNode(root->left->left);  // Print left-left child (Salmon River)
    }

    // Move to the right child of the root and print its info
    TreeNode* rightChild = moveToRightChild(root);
    printNode(rightChild);

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
