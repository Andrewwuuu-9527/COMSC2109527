// COMSC-210 | Lab 36 | Andrew
#include <iostream>
#include <string>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

int main() {
    StringBinaryTree tree;
    ifstream fin("codes.txt");
    if (!fin) {
        cout << "Error opening codes.txt\n";
        return 1;
    }
    string code;
    int count = 0;
    while (fin >> code) {
        tree.insertNode(code);
        count++;
    }
    fin.close();
    cout << "Loaded " << count << " records into the BST.\n";

    return 0;
}