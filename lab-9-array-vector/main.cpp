// COMSC-210 | Lab 9 | Andrew
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

const int SIZE = 30;    // Maximum number of temperatures to read

int main() {
    cout << "===== STD::ARRAY DEMO =====\n";

    array<double, SIZE> temps;
    ifstream fin("temperatures.txt");
    if (!fin) {
        cerr << "Error: Cannot open temperatures.txt\n";
        return 1;
    }

    int count = 0;
    while (count < SIZE && fin >> temps[count]) {
        count++;
    }
    fin.close();

    cout << "Read " << count << " temperatures.\n\n";

    // Display array size
    cout << "1. Array size: " << temps.size() << endl;

    // Display first and last temperatures
    cout << "2. First temp: " << temps.front() << endl;
    cout << "   Last temp: " << temps.back() << endl;

    // Display temperature at index 5
    cout << "3. Temp at index 5: " << temps.at(5) << endl;

    // Display raw array address
    cout << "4. Raw array address: " << temps.data() << endl;

    // Check if the array is empty
    cout << "5. Is empty: " << (temps.empty() ? "Yes" : "No") << endl;

    // Display all temperatures
    cout << "6. All temperatures: ";
    for (double t : temps) cout << t << " ";
    cout << endl << endl;

    return 0;
}