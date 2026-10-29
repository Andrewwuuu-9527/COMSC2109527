// COMSC-210 | Lab 30 | Andrew
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global constants
const int TOTAL_TICKS = 25;
const int RIDE_CAPACITY = 2;

// Function 1: Read visitor data from external file
vector<string> loadVisitors(const string& filename) {
    vector<string> visitors;
    ifstream fin(filename);
    if (!fin) {
        cout << "Error: Cannot open " << filename << endl;
        return visitors;
    }
    string name;
    while (fin >> name) {
        visitors.push_back(name);
    }
    fin.close();
    return visitors;
}

// Function 2: Display current park status
void displayParkStatus(const map<string, array<list<string>, 3>>& park) {
    cout << "--- Park Status ---\n";
    for (const auto& pair : park) {
        cout << "[" << pair.first << "] "
             << "Queue: " << pair.second[0].size() << " | "
             << "Riding: " << pair.second[1].size() << " | "
             << "Logs: " << pair.second[2].size() << "\n";
    }
    cout << "--------------------\n";
}

// Function 3: Core simulation logic
void runSimulation(map<string, array<list<string>, 3>>& park, vector<string>& visitors) {
    int visitorIndex = 0;

    for (int tick = 1; tick <= TOTAL_TICKS; tick++) {
        cout << "\n=== TIME TICK " << tick << " ===\n";

        // 1. New visitors enter the park (randomly assigned to different ride queues)
        if (visitorIndex < visitors.size()) {
            int numNewArrivals = rand() % 3 + 1; // 1 to 3 people
            for (int i = 0; i < numNewArrivals && visitorIndex < visitors.size(); i++) {
                // Randomly select a ride
                auto it = park.begin();
                advance(it, rand() % park.size());
                it->second[0].push_back(visitors[visitorIndex]);
                cout << visitors[visitorIndex] << " joined the queue for " << it->first << ".\n";
                visitorIndex++;
            }
        }

        // 2. Rides process visitors
        for (auto& pair : park) {
            string rideName = pair.first;
            auto& queue = pair.second[0];
            auto& riding = pair.second[1];
            auto& logs = pair.second[2];

            // Process visitors currently riding (unload the ride)
            while (!riding.empty()) {
                cout << riding.front() << " finished riding " << rideName << ".\n";
                riding.pop_front();
            }

            // Process queued visitors (board the ride, max 2 per ride)
            int boarded = 0;
            while (!queue.empty() && boarded < RIDE_CAPACITY) {
                string person = queue.front();
                queue.pop_front();
                riding.push_back(person);
                cout << person << " boarded " << rideName << ".\n";
                boarded++;
            }

            // Random event (10% chance of breakdown)
            if (rand() % 10 == 0) {
                logs.push_back("Ride broke down at tick " + to_string(tick));
                cout << "!!! " << rideName << " broke down!\n";
            }
        }

        // Display status after each tick
        displayParkStatus(park);
    }
}

int main() {
    srand(time(0));

    // Initialize external nested data structure
    // map: Key = ride name, Value = array<list, 3> (0: queue, 1: riding, 2: logs)
    map<string, array<list<string>, 3>> park;
    park["Roller Coaster"] = array<list<string>, 3>();
    park["Ferris Wheel"] = array<list<string>, 3>();
    park["Haunted House"] = array<list<string>, 3>();

    // Load external file
    vector<string> visitors = loadVisitors("visitors.txt");
    if (visitors.empty()) {
        cout << "No visitors loaded. Exiting.\n";
        return 1;
    }
    cout << "Loaded " << visitors.size() << " visitors from file.\n";

    // Run the simulation
    runSimulation(park, visitors);

    cout << "\nAlpha Release Simulation Complete.\n";
    return 0;
}