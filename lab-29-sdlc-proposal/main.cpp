// COMSC-210 | Lab 31 | Andrew
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Global Constants
const int TOTAL_TICKS = 25;
const int RIDE_CAPACITY = 3;
const int BREAKDOWN_CHANCE = 15; // 15% chance of breaking down
const int FIX_CHANCE = 40;       // 40% chance of fixing per tick

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

// Function 2: Display the park status in a neat table
void displayParkStatus(const map<string, array<list<string>, 3>>& park, int tick) {
    cout << "\n--- Status at Tick " << tick << " ---\n";
    cout << left << setw(16) << "Ride Name"
         << setw(10) << "Queue" 
         << setw(10) << "Riding" 
         << "Status" << "\n";
    cout << string(50, '-') << "\n";
    
    for (const auto& pair : park) {
        string status = "Operating";
        // If logs list has an odd number of entries, it's currently broken
        if (pair.second[2].size() % 2 != 0) status = "BROKEN DOWN";

        cout << left << setw(16) << pair.first
             << setw(10) << pair.second[0].size()
             << setw(10) << pair.second[1].size()
             << status << "\n";
    }
    cout << string(50, '-') << "\n";
}

// Function 3: Core simulation logic
void runSimulation(map<string, array<list<string>, 3>>& park, vector<string>& visitors) {
    int visitorIndex = 0;
    int totalBoarded = 0;

    for (int tick = 1; tick <= TOTAL_TICKS; tick++) {
        cout << "\n=== TIME TICK " << tick << " ===\n";

        // 1. New visitors arrive at the park
        if (visitorIndex < visitors.size()) {
            int numNewArrivals = rand() % 4 + 1; // 1 to 4 people
            for (int i = 0; i < numNewArrivals && visitorIndex < visitors.size(); i++) {
                auto it = park.begin();
                advance(it, rand() % park.size());
                it->second[0].push_back(visitors[visitorIndex]);
                cout << "[Entry] " << visitors[visitorIndex] << " joined queue for " << it->first << ".\n";
                visitorIndex++;
            }
        }

        // 2. Process each ride
        for (auto& pair : park) {
            string rideName = pair.first;
            auto& queue = pair.second[0];
            auto& riding = pair.second[1];
            auto& logs = pair.second[2];

            bool isBroken = (logs.size() % 2 != 0);

            // Handle Breakdown / Fixing
            if (isBroken) {
                cout << "[Maint] " << rideName << " is broken. Attempting repair...\n";
                if (rand() % 100 < FIX_CHANCE) {
                    logs.push_back("Fixed");
                    cout << "[Maint] " << rideName << " has been FIXED.\n";
                    isBroken = false;
                } else {
                    cout << "[Maint] " << rideName << " is still broken.\n";
                }
            } else {
                // Random breakdown
                if (rand() % 100 < BREAKDOWN_CHANCE) {
                    logs.push_back("Broken");
                    isBroken = true;
                    cout << "[Event] " << rideName << " BROKE DOWN!\n";
                }
            }

            if (isBroken) continue; // Skip operations if broken

            // Process visitors currently riding (they finish and leave)
            while (!riding.empty()) {
                cout << "[Exit]  " << riding.front() << " finished riding " << rideName << " and left the park.\n";
                riding.pop_front();
            }

            // Board new visitors from queue
            int boarded = 0;
            while (!queue.empty() && boarded < RIDE_CAPACITY) {
                string person = queue.front();
                queue.pop_front();
                riding.push_back(person);
                cout << "[Board] " << person << " boarded " << rideName << ".\n";
                boarded++;
                totalBoarded++;
            }
        }

        displayParkStatus(park, tick);
    }

    cout << "\n========================================\n";
    cout << "Simulation Complete!\n";
    cout << "Total Visitors Entered: " << visitorIndex << "\n";
    cout << "Total Ride Experiences: " << totalBoarded << "\n";
    cout << "Visitors Left in Queues: " << (visitors.size() - visitorIndex) << " (unentered) \n";
    cout << "========================================\n";
}

int main() {
    srand(time(0));

    map<string, array<list<string>, 3>> park;
    park["Roller Coaster"] = array<list<string>, 3>();
    park["Ferris Wheel"] = array<list<string>, 3>();
    park["Haunted House"] = array<list<string>, 3>();

    vector<string> visitors = loadVisitors("visitors.txt");
    if (visitors.empty()) {
        cout << "No visitors loaded. Exiting.\n";
        return 1;
    }
    cout << "Loaded " << visitors.size() << " visitors from file.\n";

    runSimulation(park, visitors);

    return 0;
}