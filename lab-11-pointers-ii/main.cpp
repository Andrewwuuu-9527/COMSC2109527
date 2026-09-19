// COMSC-210 | Lab 11 | Andrew
#include <iostream>
#include <string>
using namespace std;

// PizzaOrder struct
struct PizzaOrder {
    string customerName;
    int orderNumber;
    int numToppings;
    string* toppings;

    // Initialize pointer to nullptr to avoid deleting garbage when the destructor runs on a newly created object.
    PizzaOrder() : orderNumber(0), numToppings(0), toppings(nullptr) {}

    // Automatically called when the object goes out of scope. Frees the dynamically allocated toppings array to prevent memory leaks.
    ~PizzaOrder() {
        if (toppings) {
            delete[] toppings;
            toppings = nullptr;
        }
    }
};

// Function prototypes
void inputOrder(PizzaOrder& order);
void displayOrder(const PizzaOrder& order);

int main() {

    return 0;
}

// Reads data from the console for one order
void inputOrder(PizzaOrder& order){
    cout << "Customer name: ";
    getline(cin, order.customerName);

    cout << "Order number: ";
    cin >> order.orderNumber;

    cout << "How many toppings? ";
    cin >> order.numToppings;
    cin.ignore();

    order.toppings = new string[order.numToppings];

    for (int i = 0; i < order.numToppings; i++) {
        cout << "  Topping #" << i + 1 << ": ";
        getline(cin, order.toppings[i]);
}