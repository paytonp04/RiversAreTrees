#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <queue>

using namespace std;

// Structure representing a river or tributary node
struct RiverNode {
    string name;       // Name of the river/tributary
    RiverNode* left;        // Left child (tributary leading leftward)
    RiverNode* right;       // Right child (tributary leading rightward)
    RiverNode* parent;      // Pointer to the parent node

    // Constructor
    RiverNode(string riverName, RiverNode* parentNode = nullptr);
};

// Function declarations
RiverNode* createNode(string name, RiverNode* parent = nullptr);

RiverNode* returnToParent(RiverNode* current);
RiverNode* moveToRightChild(RiverNode* current);
string getLeftChildInfo(RiverNode* current);

void insertNode(RiverNode* current, string direction, std::string riverName);

void printTree(RiverNode* node, int depth);

#endif // HEADER_H
