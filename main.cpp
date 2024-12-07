#include <iostream>
#include "header.h"
#include "defintions.cpp"

int main() {

    // Create the river system
    RiverNode* mainRiver = createNode("Columbia River");
    cout << "Binary Tree of " << mainRiver -> name << endl << endl;
    printTree(mainRiver);

  return 0;
}
