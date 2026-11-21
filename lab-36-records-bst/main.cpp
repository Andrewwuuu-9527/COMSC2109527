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

    int choice = 0;
    string input, newValue;
    
    do {
        cout << "\n--- Records BST Menu ---\n";
        cout << "1. Add a record\n";
        cout << "2. Delete a record\n";
        cout << "3. Search for a record\n";
        cout << "4. Modify a record\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new record to add: ";
                cin >> input;
                tree.insertNode(input);
                cout << "Added: " << input << endl;
                break;
            case 2:
                cout << "Enter record to delete: ";
                cin >> input;
                tree.remove(input);
                cout << "Deleted (if existed): " << input << endl;
                break;
            case 3:
                cout << "Enter record to search: ";
                cin >> input;
                if (tree.searchNode(input)) {
                    cout << "Record FOUND: " << input << endl;
                } else {
                    cout << "Record NOT found.\n";
                }
                break;
            case 4:
                cout << "Enter record to modify: ";
                cin >> input;
                if (tree.searchNode(input)) {
                    cout << "Enter new record value: ";
                    cin >> newValue;
                    tree.remove(input);
                    tree.insertNode(newValue);
                    cout << "Modified " << input << " to " << newValue << endl;
                } else {
                    cout << "Record NOT found. Cannot modify.\n";
                }
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    
    return 0;
}