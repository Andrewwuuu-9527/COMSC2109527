// COMSC-210 | Lab 27 | Andrew
#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// Function to print all villager data
void printAll(const map<string, tuple<int, string, string>>& data) {
    cout << "\nVillager details:\n";
    for (const auto& pair : data) {
        cout << pair.first << " [" << get<0>(pair.second) << ", " 
             << get<1>(pair.second) << ", " << get<2>(pair.second) << "]\n";
    }
    cout << endl;
}

int main() {
    // Create a map to store villager data
    map<string, tuple<int, string, string>> villagerData;

    // Add villager data to the map
    villagerData["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagerData["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerData["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    int choice = 0;
    while (choice != 4) {
        cout << "1. Increase Friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search for Villager\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1 || choice == 2) {
            string name;
            cout << "Enter villager name: ";
            getline(cin, name);
            if (villagerData.find(name) != villagerData.end()) {
                int& friendship = get<0>(villagerData[name]); //
                if (choice == 1) {
                    friendship++;
                } else {
                    if (friendship > 0) friendship--; // Decrease friendship level
                    else cout << "Friendship is already at 0.\n";
                }
            } else {
                cout << "Villager not found.\n";
            }
        } else if (choice == 3) {
            string name;
            cout << "Enter villager name: ";
            getline(cin, name);
            if (villagerData.find(name) != villagerData.end()) {
                cout << name << " [" << get<0>(villagerData[name]) << ", " 
                     << get<1>(villagerData[name]) << ", " 
                     << get<2>(villagerData[name]) << "]\n";
            } else {
                cout << "Villager not found.\n";
            }
        }
        
        if (choice >= 1 && choice <= 3) {
            printAll(villagerData);
        }
    }
    return 0;
}