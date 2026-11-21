// COMSC-210 | Lab 36 | Andrew
#include <iostream>
#include <string>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree tree;
    tree.insertNode("Apple");
    tree.insertNode("Banana");
    tree.insertNode("Cherry");
    cout << "Test InOrder:\n";
    tree.displayInOrder();
    return 0;
}