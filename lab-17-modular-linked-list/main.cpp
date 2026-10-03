// COMSC-210 | Lab 17 | Andrew
#include <iostream>
using namespace std;

// Constants for menu options
const int MENU_MIN = 1;
const int MENU_MAX = 7;

// Node structure definition
struct Node {
    float value;
    Node* next;
};

// Function prototypes (required by coding conventions)
void addNodeFront(Node*& head, float value);
void addNodeTail(Node*& head, float value);
void deleteNode(Node*& head, int position);
void insertNode(Node*& head, int position, float value);
void deleteList(Node*& head);
void printList(Node* head);
int getValidInt(int min, int max);

int main() {
    Node* head = nullptr;
    int choice = 0;

    cout << "Modular Linked List Program\n";

    return 0;
}

// Function to get a valid integer input from the user within a specified range
int getValidInt(int min, int max) {
    int value;
    while (true) {
        if (cin >> value && value >= min && value <= max) {
            return value;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter a number between "
             << min << " and " << max << ": ";
    }
}

// Function to add a new node at the front of the linked list
void addNodeFront(Node*& head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

// Function to add a new node at the tail of the linked list
void addNodeTail(Node*& head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}