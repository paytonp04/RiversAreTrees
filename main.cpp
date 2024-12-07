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


int main() {

    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(20);

    Node* rightChild = tree.moveToRightChild(tree.root);
    tree.printNodeInfo(rightChild);

    return 0;
}
