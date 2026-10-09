// COMSC-210 | Lab 20 | Andrew
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 3;
const int MIN_LEGS = 3;
const int MAX_LEGS = 4;
const int MIN_PRICE = 10000;
const int MAX_PRICE = 99999;

class Chair {
private:
    int legs;
    double * prices;
public:
    // Default constructor: random legs (3 or 4) and random prices ($100.00-$999.99)
    Chair() {
        prices = new double[SIZE];
        legs = rand() % (MAX_LEGS - MIN_LEGS + 1) + MIN_LEGS;
        for (int i = 0; i < SIZE; i++) {
            int priceInCents = rand() % (MAX_PRICE - MIN_PRICE + 1) + MIN_PRICE;
            prices[i] = priceInCents / 100.0;
        }
    }
    // Constructor with legs and prices
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));
    cout << fixed << setprecision(2);

    // 1. Default constructor + setters
    cout << "=== Chair #1: Default constructor + setters ===\n";
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    // 2. Parameter constructor with legs and price array
    cout << "=== Chair #2: Parameter constructor ===\n";
    double prices2[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices2);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // 3. Dynamic array using DEFAULT constructor
    //    Each object gets random legs and random prices
    cout << "=== Chairs #3-#5: Dynamic array with default constructor ===\n";
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    delete[] collection;
    collection = nullptr;

    return 0;
}