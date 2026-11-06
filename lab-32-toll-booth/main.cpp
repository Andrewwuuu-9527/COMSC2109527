// COMSC-210 | Lab 32 | Andrew
#include <iostream>

#include <deque>

#include <cstdlib>

#include <ctime>

#include "Car.h"

using namespace std;

// Function to print the contents of a deque of Car objects
void printQueue(deque < Car > lane) {
    cout << "Queue: " << endl;
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

    deque < Car > lane;

    lane.push_back(Car());
    lane.push_back(Car());

    cout << "Initial queue:" << endl;
    printQueue(lane);

    // Simulate the passage of time and random operations on the queue
    int time = 1;
    while (!lane.empty()) {
        int chance = rand() % 100 + 1; // Random number between 1 and 100

        if (chance <= 55) {
            // 55% chance to remove a car from the front of the queue
            cout << "\nTime: " << time << " Operation: Car paid: ";
            lane.front().print();
            lane.pop_front();
        } else {
            // 45% chance for a new car to join the queue
            lane.push_back(Car());
            cout << "\nTime: " << time << " Operation: Joined lane: ";
            lane.back().print();
        }

        printQueue(lane);
        time++;
    }

    return 0;
}