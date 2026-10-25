// COMSC-210 | Lab 28 | Andrew
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
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
                string searchName; cout << "Enter name: "; cin >> searchName;
                auto it = find_if(trip.begin(), trip.end(), [&](const Goat& g) { return g.get_name() == searchName; });
                if (it != trip.end()) cout << "Found: " << it->get_name() << "\n";
                else cout << "Not found.\n";
                break;
            }
            
            // Milestone 2: count_if
            case 6: {
                int ageLimit;
                cout << "Enter age limit: ";
                cin >> ageLimit;
                int count = count_if(trip.begin(), trip.end(), [&](const Goat& g) {
                    return g.get_age() > ageLimit;
                });
                cout << "Number of goats older than " << ageLimit << ": " << count << "\n";
                break;
            }

            // Milestone 3: max_element / min_element
            case 7: {
                if (trip.empty()) { cout << "Trip is empty.\n"; break; }
                auto maxIt = max_element(trip.begin(), trip.end(), [](const Goat& a, const Goat& b) { return a.get_age() < b.get_age(); });
                auto minIt = min_element(trip.begin(), trip.end(), [](const Goat& a, const Goat& b) { return a.get_age() < b.get_age(); });
                cout << "Oldest: " << maxIt->get_name() << " (" << maxIt->get_age() << ")\n";
                cout << "Youngest: " << minIt->get_name() << " (" << minIt->get_age() << ")\n";
                break;
            }

            // Milestone 4: accumulate
            case 8: {
                int totalAge = accumulate(trip.begin(), trip.end(), 0, [](int sum, const Goat& g) {
                    return sum + g.get_age();
                });
                cout << "Total age of all goats: " << totalAge << "\n";
                break;
            }

            // Milestone 5: any_of
            case 9: {
                bool hasOldGoat = any_of(trip.begin(), trip.end(), [](const Goat& g) {
                    return g.get_age() > 15;
                });
                if (hasOldGoat) cout << "Yes, there is at least one goat older than 15.\n";
                else cout << "No goats older than 15.\n";
                break;
            }

            // Milestone 6: for_each
            case 10: {
                for_each(trip.begin(), trip.end(), [](Goat& g) {
                    g.set_age(g.get_age() + 1);
                });
                cout << "All goats have aged by 1 year.\n";
                break;
            }

            // Milestone 7: list::sort
            case 11: {
                trip.sort([](const Goat& a, const Goat& b) {
                    return a.get_age() < b.get_age();
                });
                cout << "Goats sorted by age.\n";
                display_trip(trip);
                break;
            }
        }
    }
    return 0;
}

// Display the main menu and return the user's choice
int main_menu() {
    int choice; bool valid = false;
    while (!valid) {
        cout << "\n*** GOAT MANAGER 3001 ***\n";
        cout << "[1] Add\n[2] Delete\n[3] List\n[4] Quit\n";
        cout << "[5] Search by name (find_if)\n";
        cout << "[6] Count older than age (count_if)\n";
        cout << "[7] Find oldest/youngest (max/min_element)\n";
        cout << "[8] Calculate total age (accumulate)\n";
        cout << "[9] Any older than 15 (any_of)\n";
        cout << "[10] Increase all ages by 1 (for_each)\n";
        cout << "[11] Sort by age (list::sort)\n";
        cout << "Choice --> "; cin >> choice;
        if (cin.fail() || choice < 1 || choice > 11) { cin.clear(); cin.ignore(10000, '\n'); }
        else valid = true;
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