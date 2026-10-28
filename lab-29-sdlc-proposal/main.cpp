// COMSC-210 | Lab 29 | Andrew
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <vector>
using namespace std;

// PSEUDOCODE (Step-by-step logic framework for the final simulation)

/*
 * Function: runSimulation
 * Parameters: std::map<string, array<list<string>, 3>>& park, int totalTicks
 * 
 * BEGIN runSimulation
 *   FOR tick = 1 to totalTicks:
 *     Print "--- Time Tick " << tick << " ---"
 *     
 *     FOR EACH ride IN park:
 *       // 1. Check maintenance status
 *       IF ride's maintenance list is not empty:
 *         IF random event == fix:
 *           clear maintenance list
 *           Print "Ride is fixed!"
 *         ELSE:
 *           Print "Ride is broken, skipping..."
 *           CONTINUE to next ride
 *           
 *       // 2. Process queue
 *       IF ride's queue list is not empty:
 *         Move first person from Queue (index 0) to Riding (index 1)
 *         
 *       // 3. Complete ride
 *       IF ride's riding list is not empty:
 *         Remove first person from Riding (index 1)
 *         
 *       // 4. Random Breakdown
 *       IF random chance:
 *         Add "Broken" to Maintenance list (index 2)
 *         
 *       Print current queue and riding status
 *   END FOR
 * END runSimulation
 */

// MOCKUP (Wireframe code)

// Mockup function to demonstrate data passing
void displayParkStatus(const map<string, array<list<string>, 3>>& park) {
    cout << "Initial Mockup State:\n";
    for (const auto& pair : park) {
        cout << "Ride: " << pair.first << endl;
        // pair.second is the array of 3 lists
        cout << "  Queue size: " << pair.second[0].size() << endl;
        cout << "  Riding size: " << pair.second[1].size() << endl;
        cout << "  Maintenance logs: " << pair.second[2].size() << endl;
    }
    cout << "-----------------------------------\n";
}

int main() {
    // 1. Declare the nested data structure
    // Key: string (Ride Name), Value: array of 3 lists
    map<string, array<list<string>, 3>> park;

    // 2. Setup some dummy data (Mockup style)
    // In the final version, this will read from visitors.txt
    park["Roller Coaster"][0].push_back("Alice"); // Alice is in queue
    park["Roller Coaster"][0].push_back("Bob");
    park["Roller Coaster"][1].push_back("Charlie"); // Charlie is riding
    
    park["Ferris Wheel"][0].push_back("David");
    
    // 3. Call the function to prove the data structure is valid and passing works
    displayParkStatus(park);

    // 4. Here is where the runSimulation(park, 25); will go in Lab 30.
    cout << "Mockup complete. Simulation logic will be added in Lab 30.\n";

    return 0;
}