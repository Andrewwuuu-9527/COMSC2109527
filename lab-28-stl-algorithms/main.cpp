// COMSC-210 | Lab 28 | Andrew
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Goat.h"
using namespace std;

// Constants
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

// Function prototypes
void add_goat(list<Goat>& trip, string names[], string colors[]);
void delete_goat(list<Goat>& trip);
void display_trip(list<Goat> trip);
int select_goat(list<Goat>& trip);
int main_menu();

int main() {
    srand(time(0));

    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;
    bool again = true;
    while (again) {
        int choice = main_menu();
        switch (choice) {
            case 1: add_goat(trip, names, colors); break;
            case 2: delete_goat(trip); break;
            case 3: display_trip(trip); break;
            case 4: again = false; break;
            
            // Milestone 1: find_if
            case 5: {
                string searchName;
                cout << "Enter name to search: ";
                cin >> searchName;
                auto it = find_if(trip.begin(), trip.end(), [&](const Goat& g) {
                    return g.get_name() == searchName;
                });
                if (it != trip.end())
                    cout << "Found: " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")\n";
                else
                    cout << "Goat not found.\n";
                break;
            }
        }
    }
    return 0;
}

// Display the main menu and return the user's choice
int main_menu() {
    int choice;
    bool valid = false;
    while (!valid) {
        cout << "\n*** GOAT MANAGER 3001 ***\n";
        cout << "[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\n";
        cout << "[5] Search by name (find_if)\n";
        cout << "Choice --> ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Invalid choice.\n";
        } else valid = true;
    }
    return choice;
}

// Add a goat to the list
void add_goat(list<Goat>& trip, string names[], string colors[]) {
    string n = names[rand() % SZ_NAMES];
    int a = rand() % (MAX_AGE + 1);
    string c = colors[rand() % SZ_COLORS];
    trip.push_back(Goat(n, a, c));
    cout << "Added: " << n << " (" << a << ", " << c << ")\n";
}

// Display the list of goats
void display_trip(list<Goat> trip) {
    if (trip.empty()) { cout << "No goats.\n"; return; }
    int count = 1;
    for (auto it = trip.begin(); it != trip.end(); ++it) {
        cout << "[" << count++ << "] " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")\n";
    }
}

// Select a goat from the list and return its index (1-based)
int select_goat(list<Goat>& trip) {
    if (trip.empty()) return -1;
    display_trip(trip);
    int choice;
    bool valid = false;
    while (!valid) {
        cout << "Select a goat: "; cin >> choice;
        if (cin.fail() || choice < 1 || choice > (int)trip.size()) {
            cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid.\n";
        } else valid = true;
    }
    return choice;
}

// Delete a goat from the list
void delete_goat(list<Goat>& trip) {
    int choice = select_goat(trip);
    if (choice == -1) return;
    auto it = trip.begin();
    advance(it, choice - 1);
    cout << "Removed: " << it->get_name() << "\n";
    trip.erase(it);
}