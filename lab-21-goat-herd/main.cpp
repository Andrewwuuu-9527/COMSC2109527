// COMSC-210 | Lab 21 | Andrew
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_NAMES = 15;
const int NUM_COLORS = 15;
const int MIN_AGE = 1;
const int MAX_AGE = 20;
const int MIN_GOATS = 5;
const int MAX_GOATS = 20;

class Goat {
private:
    int age;
    string name;
    string color;
    string names[NUM_NAMES] = {
        "Senior", "Godlike", "Old", "Mature", "Teen",
        "Young", "Kid", "Baby", "Elder", "Ancient",
        "Legendary", "Heroic", "Mystic", "Wise", "Swift"
    };
    string colors[NUM_COLORS] = {
        "Yellow", "Red", "Gold", "Mauve", "White",
        "Black", "Brown", "Gray", "Blue", "Green",
        "Orange", "Pink", "Purple", "Silver", "Cyan"
    };

public:
    Goat();
    Goat(int a, string n, string c);
    int getAge() const;
    string getName() const;
    string getColor() const;
    void print() const;
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    void push_back(Goat value);
    void push_front(Goat value);
    void print();
    void print_reverse();
    ~DoublyLinkedList();
};

// Default constructor: random age (1-20), random name, random color
Goat::Goat() {
    age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
    name = names[rand() % NUM_NAMES];
    color = colors[rand() % NUM_COLORS];
}

// Parameter constructor: explicit age, name, color
Goat::Goat(int a, string n, string c) {
    age = a;
    name = n;
    color = c;
}

int Goat::getAge() const { return age; }
string Goat::getName() const { return name; }
string Goat::getColor() const { return color; }

// print() outputs the goat's info in the format "name (color, age)"
void Goat::print() const {
    cout << "    " << name << " (" << color << ", " << age << ")" << endl;
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

// push_back() adds a Goat to the end of the list
void DoublyLinkedList::push_back(Goat value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// push_front() adds a Goat to the front of the list
void DoublyLinkedList::push_front(Goat value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// print() traverses forward, printing each Goat
void DoublyLinkedList::print() {
    cout << "Forward:" << endl;
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    while (current) {
        current->data.print();
        current = current->next;
    }
    cout << endl;
}

// print_reverse() traverses backward using prev pointers
void DoublyLinkedList::print_reverse() {
    cout << "Backward:" << endl;
    if (!tail) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = tail;
    while (current) {
        current->data.print();
        current = current->prev;
    }
}

// Destructor frees all nodes
DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    return 0;
}