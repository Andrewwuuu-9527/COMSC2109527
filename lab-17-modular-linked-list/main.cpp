// COMSC-210 | Lab 17 | Andrew
#include <iostream>

using namespace std;

// Constants for menu options
const int MENU_MIN = 1;
const int MENU_MAX = 7;

// Node structure definition
struct Node {
    float value;
    Node * next;
};

// Function prototypes (required by coding conventions)
void addNodeFront(Node * & head, float value);
void addNodeTail(Node * & head, float value);
void deleteNode(Node * & head, int position);
void insertNode(Node * & head, int position, float value);
void deleteList(Node * & head);
void printList(Node * head);
int getValidInt(int min, int max);

int main() {
    Node * head = nullptr;
    int choice = 0;
    float value;
    int position;

    do {
        // Display the menu
        cout << "\n===== Linked List Menu =====\n";
        cout << "1. Add a node to the front\n";
        cout << "2. Add a node to the end\n";
        cout << "3. Delete a node\n";
        cout << "4. Insert a node\n";
        cout << "5. Delete the entire list\n";
        cout << "6. Print the list\n";
        cout << "7. Exit\n";
        cout << "Choice --> ";

        // Validate menu choice (must be integer 1-7)
        choice = getValidInt(MENU_MIN, MENU_MAX);

        switch (choice) {
        case 1:
            cout << "Enter value to add at front: ";
            cin >> value;
            addNodeFront(head, value);
            cout << "Node added at front.\n";
            break;
        case 2:
            cout << "Enter value to add at end: ";
            cin >> value;
            addNodeTail(head, value);
            cout << "Node added at end.\n";
            break;
        case 3:
            cout << "Enter position to delete (1-based): ";
            position = getValidInt(1, 1000);
            deleteNode(head, position);
            break;
        case 4:
            cout << "Insert after position (0 for front): ";
            position = getValidInt(0, 1000);
            cout << "Enter value to insert: ";
            cin >> value;
            insertNode(head, position, value);
            break;
        case 5:
            deleteList(head);
            cout << "Entire list deleted.\n";
            break;
        case 6:
            printList(head);
            break;
        case 7:
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    } while (choice != 7);

    // Clean up any remaining nodes before exit
    deleteList(head);
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
        cout << "Invalid input. Enter a number between " <<
            min << " and " << max << ": ";
    }
}

// Function to add a new node at the front of the linked list
void addNodeFront(Node * & head, float value) {
    Node * newNode = new Node;
    newNode -> value = value;
    newNode -> next = head;
    head = newNode;
}

// Function to add a new node at the tail of the linked list
void addNodeTail(Node * & head, float value) {
    Node * newNode = new Node;
    newNode -> value = value;
    newNode -> next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node * current = head;
    while (current -> next != nullptr) {
        current = current -> next;
    }
    current -> next = newNode;
}

// Function to delete a node at a specified position in the linked list
void deleteNode(Node * & head, int position) {
    if (head == nullptr) {
        cout << "Error: List is empty, nothing to delete.\n";
        return;
    }

    // Validate position by counting nodes
    int count = 0;
    Node * current = head;
    while (current) {
        count++;
        current = current -> next;
    }

    if (position < 1 || position > count) {
        cout << "Error: Position " << position <<
            " is out of range (1 to " << count << ").\n";
        return;
    }

    // Special case: deleting the head node
    if (position == 1) {
        Node * temp = head;
        head = head -> next;
        delete temp;
        return;
    }

    // Traverse to the node just before the target
    current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current -> next;
    }
    Node * temp = current -> next;
    current -> next = temp -> next;
    delete temp;
}

// Function to insert a new node at a specified position in the linked list
void insertNode(Node * & head, int position, float value) {
    Node * newNode = new Node;
    newNode -> value = value;

    // Insert at front (position 0)
    if (position == 0) {
        newNode -> next = head;
        head = newNode;
        return;
    }

    // Traverse to the node at the given position
    Node * current = head;
    for (int i = 1; i < position && current != nullptr; i++) {
        current = current -> next;
    }

    if (current == nullptr) {
        cout << "Error: Position " << position <<
            " is out of range. Insertion cancelled.\n";
        delete newNode;
        return;
    }

    newNode -> next = current -> next;
    current -> next = newNode;
}

// Function to delete the entire linked list and free memory
void deleteList(Node * & head) {
    Node * current = head;
    while (current) {
        Node * temp = current;
        current = current -> next;
        delete temp;
    }
    head = nullptr;
}

// Function to print the linked list
void printList(Node * head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    int count = 1;
    Node * current = head;
    while (current) {
        cout << "[" << count++ << "] " << current -> value << endl;
        current = current -> next;
    }
}