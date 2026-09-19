// COMSC-210 | Lab 11 | Andrew
#include <iostream>
#include <string>
using namespace std;

struct PizzaOrder {
    string customerName;
    int orderNumber;
    int numToppings;
    string* toppings;

    PizzaOrder() : orderNumber(0), numToppings(0), toppings(nullptr) {}

    ~PizzaOrder() {
        if (toppings) {
            delete[] toppings;
            toppings = nullptr;
        }
    }
};

int main() {

    return 0;
}