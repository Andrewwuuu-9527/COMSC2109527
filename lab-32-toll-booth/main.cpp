// COMSC-210 | Lab 32 | Andrew
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

// Function to print the contents of a deque of Car objects
void printQueue(deque<Car> lane) {
    cout << "Queue: "<< endl;
    if (lane.empty()) {
        cout << "    Empty" << endl;
        return;
    }
    for (auto car : lane) {
        cout << "    ";
        car.print();
    }
}

int main() {
    srand(time(0));

    deque<Car> lane;

    cout << "Initial queue:" << endl;
    printQueue(lane);

    return 0;
}