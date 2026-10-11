#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value);
    void push_front(int value);
    void insert_after(int value, int position);
    void delete_val(int value);   
    void delete_pos(int position);   
    void pop_front();              
    void pop_back();                
    void print();
    void print_reverse();
    ~DoublyLinkedList();
};

// Insert a new node at the end of the list
void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Insert a new node at the front of the list
void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert a new node after a given position
void DoublyLinkedList::insert_after(int value, int position) {
    if (position < 0) {
        cout << "Position must be >= 0." << endl;
        return;
    }
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < position && temp; ++i)
        temp = temp->next;

    if (!temp) {
        cout << "Position exceeds list size. Node not inserted.\n";
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    else
        tail = newNode;
    temp->next = newNode;
}


// Print the list in forward order
void DoublyLinkedList::print() {
    Node* current = head;
    if (!current) {
        cout << "List is empty" << endl;
        return;
    }
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


// Print the list in reverse order
void DoublyLinkedList::print_reverse() {
    Node* current = tail;
    if (!current) {
        cout << "List is empty" << endl;
        return;
    }
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

// Destructor to free memory
DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Delete a node with a specific value
void DoublyLinkedList::delete_val(int value) {
    if (!head) return;   // Empty list

    // Find the node with the matching value
    Node* temp = head;
    while (temp && temp->data != value)
        temp = temp->next;

    if (!temp) return;   // Value not found

    // Relink previous node (or update head)
    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    // Relink next node (or update tail)
    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    delete temp;
}

// Delete a node at a specific position (1-based index)
void DoublyLinkedList::delete_pos(int position) {
    if (!head) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (position < 1) {
        cout << "Position must be >= 1." << endl;
        return;
    }

    // Traverse to the target node
    Node* temp = head;
    for (int i = 1; i < position && temp; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position exceeds list size. Nothing deleted." << endl;
        return;
    }

    // Relink previous node (or update head)
    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    // Relink next node (or update tail)
    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    delete temp;
}

// Remove the first node of the list
void DoublyLinkedList::pop_front() {
    if (!head) {
        cout << "List is empty. Nothing to pop." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;   // List became empty
    }
    delete temp;
}

// Remove the last node of the list
void DoublyLinkedList::pop_back() {
    if (!tail) {
        cout << "List is empty. Nothing to pop." << endl;
        return;
    }

    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;   // List became empty
    }
    delete temp;
}

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    cout << "List forward: ";
    list.print();

    return 0;
}
