// COMSC-210 | Lab 27 | Andrew
#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // Create a map to store villager data
    map<string, tuple<int, string, string>> villagerData;

    // Add villager data to the map
    villagerData["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagerData["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerData["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    // Display villager details
    cout << "Villager details:" << endl;
    for (const auto& pair : villagerData) {
        string name = pair.first;
        // Unpack the tuple into individual variables
        int friendship = get<0>(pair.second);
        string species = get<1>(pair.second);
        string catchphrase = get<2>(pair.second);

        cout << name << " [" << friendship << ", " 
             << species << ", " << catchphrase << "]" << endl;
    }

    return 0;
}