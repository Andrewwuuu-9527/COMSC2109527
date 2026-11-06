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

    lane.push_back(Car());
    lane.push_back(Car());

    cout << "Initial queue:" << endl;
    printQueue(lane);

    // Simulate the passage of time and random operations on the queue
    int time = 1;
    while (!lane.empty()) {
        cout << "\nTime: " << time << " ";

        int chance = rand() % 100 +1;   // Random number between 1 and 100

        cout << "Operation: Random value is " << chance << endl;

        printQueue(lane);
        time++;

        if (time > 5) break; // Limit the simulation to 5 time units for demonstration
    }

    return 0;
}