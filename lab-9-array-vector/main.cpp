// COMSC-210 | Lab 9 | Andrew
#include <iostream>

#include <fstream>

#include <array>

#include <vector>

#include <algorithm>

#include <numeric>

#include <iomanip>

using namespace std;

const int SIZE = 30; // Maximum number of temperatures to read

int main() {
    // Array demonstration
    cout << "===== STD::ARRAY DEMO =====\n";

    // Declare an array to hold temperatures
    array < double, SIZE > temps;
    ifstream fin("temperatures.txt");
    if (!fin) {
        cerr << "Error: Cannot open temperatures.txt\n";
        return 1;
    }

    // Read temperatures into the array
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
    for (double t: temps) cout << t << " ";
    cout << endl;

    // Sort in descending order and display
    sort(temps.rbegin(), temps.rend());
    cout << "7. Descending order: ";
    for (double t: temps) cout << t << " ";
    cout << endl;

    // Search for a specific temperature
    double target = 75.1;
    auto it = find(temps.begin(), temps.end(), target);
    if (it != temps.end())
        cout << "8. Found " << target << " at position " << (it - temps.begin()) << endl;
    else
        cout << "8. " << target << " not found.\n";

    // Display max and min temperatures
    cout << "9. Max temp: " << * max_element(temps.begin(), temps.end()) << endl;
    cout << "10. Min temp: " << * min_element(temps.begin(), temps.end()) << endl;

    // Calculate sum and average of temperatures
    double sum = accumulate(temps.begin(), temps.end(), 0.0);
    cout << "11. Sum: " << sum << endl;
    cout << "12. Average: " << (sum / temps.size()) << endl;

    // Fill an array with a specific value and display it
    array < double, 5 > testFill;
    testFill.fill(99.9);
    cout << "13. fill() demo: ";
    for (double t: testFill) cout << t << " ";
    cout << endl;

    // Swap two arrays and display the result
    array < double, 5 > arrA = {
        1,
        2,
        3,
        4,
        5
    };
    array < double, 5 > arrB = {
        10,
        20,
        30,
        40,
        50
    };
    arrA.swap(arrB);
    cout << "14. After swap, arrA: ";
    for (double t: arrA) cout << t << " ";
    cout << endl << endl;

    // Vector demonstration
    cout << "===== STD::VECTOR DEMO =====\n";

    // Declare a vector to hold temperatures
    vector < double > vTemps;
    fin.open("temperatures.txt");
    if (!fin) {
        cout << "Error: Cannot open temperatures.txt\n";
        return 1;
    }
    double val;
    while (fin >> val) {
        vTemps.push_back(val);
    }
    fin.close();

    // Display vector size
    cout << "Read " << vTemps.size() << " temperatures into vector.\n\n";

    // Display vector properties
    cout << "1. Vector size: " << vTemps.size() << endl;
    cout << "2. First temp: " << vTemps.front() << endl;
    cout << "   Last temp:  " << vTemps.back() << endl;
    cout << "3. Temp at index 5: " << vTemps.at(5) << endl;
    cout << "4. Raw array address: " << vTemps.data() << endl;
    cout << "5. Is empty? " << (vTemps.empty() ? "Yes" : "No") << endl;

    // Sort the vector and display it
    sort(vTemps.begin(), vTemps.end());
    cout << "6. Sorted temperatures: ";
    for (double t: vTemps) cout << t << " ";
    cout << endl;

    // Sort in descending order and display
    sort(vTemps.rbegin(), vTemps.rend());
    cout << "7. Descending order: ";
    for (double t: vTemps) cout << t << " ";
    cout << endl;

    // Sort in descending order and display
    auto vit = find(vTemps.begin(), vTemps.end(), target);
    if (vit != vTemps.end())
        cout << "8. Found " << target << " at position " << (vit - vTemps.begin()) << endl;
    else
        cout << "8. " << target << " not found.\n";

    // Display max and min temperatures
    cout << "9. Max temp: " << * max_element(vTemps.begin(), vTemps.end()) << endl;
    cout << "10. Min temp: " << * min_element(vTemps.begin(), vTemps.end()) << endl;

    // Calculate sum and average of vector temperatures
    double vSum = accumulate(vTemps.begin(), vTemps.end(), 0.0);
    cout << "11. Sum: " << vSum << endl;
    cout << "12. Average: " << vSum / vTemps.size() << endl;

    // Demonstrate vector modification methods
    vTemps.push_back(100.0);
    cout << "13. After push_back(100.0), size = " << vTemps.size() << endl;

    // Remove the last element
    vTemps.pop_back();
    cout << "14. After pop_back(), size = " << vTemps.size() << endl;

    // Insert a value at index 2
    vTemps.insert(vTemps.begin() + 2, 55.5);
    cout << "15. After insert at index 2: " << vTemps[2] << endl;

    // Erase the value at index 2
    vTemps.erase(vTemps.begin() + 2);
    cout << "16. After erase at index 2: " << vTemps[2] << endl;

    // Clear the vector and check if it's empty
    vTemps.clear();
    cout << "17. After clear(), is empty? " << (vTemps.empty() ? "Yes" : "No") << endl;

    return 0;
}