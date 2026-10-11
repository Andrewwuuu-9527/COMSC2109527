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
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
