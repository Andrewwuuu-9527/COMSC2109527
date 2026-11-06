// COMSC-210 | Lab 33 | Andrew
#include <iostream>

#include <deque>

#include <array>

#include <cstdlib>

#include <ctime>

#include "Car.h"

using namespace std;

const int NUM_LANES = 4;

// Function to print the contents of a lane
void printLane(int laneNum, deque<Car> lane) {
    cout << "Lane " << laneNum << " Queue: " << endl;
    if (lane.empty()) {
        cout << "    Empty" << endl;
        return;
    }
    for (auto car: lane) {
        cout << "    ";
        car.print();
    }
}

int main() {
    srand(time(0));

    // Create an array of deques to represent the lanes in the toll plaza
    array<deque<Car>, NUM_LANES> plaza;

    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        // Add two cars to each lane
        for (int j = 0; j < 2; j++) {
            plaza[i].push_back(Car());
        }
        printLane(i + 1, plaza[i]);
    }

    return 0;
}