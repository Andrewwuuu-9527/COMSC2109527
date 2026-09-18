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

    // Sort the temperatures and display them
    sort(temps.begin(), temps.end());
    cout << "6. Sorted temperatures: ";
    for (double t : temps) cout << t << " ";
    cout << endl;

    // Sort in descending order and display
    sort(temps.rbegin(), temps.rend());
    cout << "7. Descending order: ";
    for (double t : temps) cout << t << " ";
    cout << endl;

    // Search for a specific temperature
    double target = 75.1;
    auto it = find(temps.begin(), temps.end(), target);
    if (it != temps.end())
        cout << "8. Found " << target << " at position " << (it - temps.begin()) << endl;
    else
        cout << "8. " << target << " not found.\n";

    // Display max and min temperatures
    cout << "9. Max temp: " << *max_element(temps.begin(), temps.end()) << endl;
    cout << "10. Min temp: " << *min_element(temps.begin(), temps.end()) << endl;
    
    // Calculate sum and average of temperatures
    double sum = accumulate(temps.begin(), temps.end(), 0.0);
    cout << "11. Sum: " << sum << endl;
    cout << "12. Average: " << (sum / temps.size()) << endl;

    // Fill an array with a specific value and display it
    array<double, 5> testFill;
    testFill.fill(99.9);
    cout << "13. fill() demo: ";
    for (double t : testFill) cout << t << " ";
    cout << endl;

    // Swap two arrays and display the result
    array<double, 5> arrA = {1, 2, 3, 4, 5};
    array<double, 5> arrB = {10, 20, 30, 40, 50};
    arrA.swap(arrB);
    cout << "14. After swap, arrA: ";
    for (double t : arrA) cout << t << " ";
    cout << endl << endl;

    return 0;
}