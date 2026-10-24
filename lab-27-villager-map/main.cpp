// COMSC-210 | Lab 27 | Andrew
#include <iostream>

#include <map>

#include <tuple>

#include <string>

using namespace std;

// Function to print all villager data
void printAll(const map < string, tuple < int, string, string >> & data) {
    cout << "\nVillager details:\n";
    for (const auto & pair: data) {
        cout << pair.first << " [" << get < 0 > (pair.second) << ", " <<
            get < 1 > (pair.second) << ", " << get < 2 > (pair.second) << "]\n";
    }
    cout << endl;
}

int main() {
    // Create a map to store villager data
    map < string, tuple < int, string, string >> villagerData;

    int choice = 0;

    // Menu loop
    while (choice != 6) {
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        string name;
        if (choice == 1) {
            int friendship;
            string species, catchphrase;
            cout << "Villager name: ";
            getline(cin, name);
            cout << "Friendship level: ";
            cin >> friendship;
            cin.ignore();
            cout << "Species: ";
            getline(cin, species);
            cout << "Catchphrase: ";
            getline(cin, catchphrase);

            villagerData[name] = make_tuple(friendship, species, catchphrase);
            cout << name << " added.\n";
            printAll(villagerData);
        } else if (choice == 2) {
            cout << "Villager name: ";
            getline(cin, name);
            if (villagerData.erase(name)) {
                cout << name << " deleted.\n";
            } else {
                cout << "Villager not found.\n";
            }
            printAll(villagerData);
        } else if (choice == 3 || choice == 4) {
            cout << "Villager name: ";
            getline(cin, name);
            if (villagerData.find(name) != villagerData.end()) {
                int & friendship = get < 0 > (villagerData[name]);
                if (choice == 3) {
                    friendship++;
                } else {
                    if (friendship > 0) friendship--;
                }
            } else {
                cout << "Villager not found.\n";
            }
            printAll(villagerData);
        } else if (choice == 5) {
            cout << "Villager name: ";
            getline(cin, name);
            if (villagerData.find(name) != villagerData.end()) {
                cout << name << " [" << get < 0 > (villagerData[name]) << ", " <<
                    get < 1 > (villagerData[name]) << ", " <<
                    get < 2 > (villagerData[name]) << "]\n";
            } else {
                cout << "Villager not found.\n";
            }
        }
    }
    return 0;
}