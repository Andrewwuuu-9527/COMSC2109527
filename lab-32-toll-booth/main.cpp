// COMSC-210 | Lab 33 | Andrew
#include <iostream>

#include <deque>

#include <array>

#include <cstdlib>

#include <ctime>

#include "Car.h"

using namespace std;

const int NUM_LANES = 4;
const int PAY_PROB = 46;
const int JOIN_PROB = 39;
const int SWITCH_PROB = 15;
const int EMPTY_JOIN_PROB = 50;


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

    const int TOTAL_TICKS = 20;

    for (int time = 1; time <= TOTAL_TICKS; time++) {
        cout << "\nTime: " << time << "\n";

        for (int i = 0; i < NUM_LANES; i++) {
            int chance = rand() % 100;

            if (plaza[i].empty()) {
                // If the lane is empty, add a new car with a 50% chance
                if (chance < EMPTY_JOIN_PROB) {
                    plaza[i].push_back(Car());
                    cout << "Lane: " << i + 1 << " Joined: ";
                    plaza[i].back().print();
                } 
            }else {
                // If the lane is not empty, either remove the front car or add a new car with a 50% chance
                if (chance < PAY_PROB) {
                    cout << "Lane: " << i + 1 << " Joined: ";
                    plaza[i].front().print();
                    plaza[i].pop_front();
                }
                else if (chance < PAY_PROB + JOIN_PROB) {
                    plaza[i].push_back(Car());
                    cout << "Lane: " << i + 1 << " Joined: ";
                    plaza[i].back().print();
                }
                else {
                    int newLane = rand() % NUM_LANES;

                    while (newLane == i) {
                        newLane = rand() % NUM_LANES;
                    }

                    Car switchingCar = plaza[i].back();
                    plaza[i].pop_back();
                    plaza[newLane].push_back(switchingCar);

                    cout << "Lane: " << i + 1 << " Switched: ";
                    switchingCar.print();

                }
            }
        }

        // Print the final state of the lanes
        for (int i = 0; i < NUM_LANES; i++) {
            printLane(i + 1, plaza[i]);
        }
    }    

    return 0;
}