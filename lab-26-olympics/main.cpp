// COMSC-210 | Lab 25 | Andrew
#include <iostream>

#include <fstream>

#include <vector>

#include <list>

#include <set>

#include <string>

#include <chrono>

#include <iomanip>

#include <algorithm>

using namespace std;
using namespace std::chrono;

// Structure to store the timing results of a single race
struct RaceResult {
    string operationName;
    long long vectorTime;
    long long listTime;
    long long setTime;
};

int main() {
    // Read the data file (usually codes.txt or a similar name in Starter code)
    ifstream fin("codes.txt");
    if (!fin) {
        cout << "Error: Cannot open codes.txt\n";
        return 1;
    }

    // All competition results
    vector < RaceResult > results;

    // RACE 1: READING
    RaceResult readRace;
    readRace.operationName = "Read";

    // Vector reading
    auto start = high_resolution_clock::now();
    vector < string > vec;
    string line;
    while (fin >> line) vec.push_back(line);
    auto end = high_resolution_clock::now();
    readRace.vectorTime = duration_cast < nanoseconds > (end - start).count();

    fin.clear(); // Clear EOF flag
    fin.seekg(0, ios::beg);

    // List reading
    start = high_resolution_clock::now();
    list < string > lst;
    while (fin >> line) lst.push_back(line);
    end = high_resolution_clock::now();
    readRace.listTime = duration_cast < nanoseconds > (end - start).count();

    fin.clear();
    fin.seekg(0, ios::beg);

    // Set reading
    start = high_resolution_clock::now();
    set < string > st;
    while (fin >> line) st.insert(line);
    end = high_resolution_clock::now();
    readRace.setTime = duration_cast < nanoseconds > (end - start).count();

    fin.close();
    results.push_back(readRace);

    // RACE 2: SORTING
    RaceResult sortRace;
    sortRace.operationName = "Sort";

    // Sort the vector and measure the time taken
    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    sortRace.vectorTime = duration_cast < nanoseconds > (end - start).count();

    // Sort the list and measure the time taken
    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    sortRace.listTime = duration_cast < nanoseconds > (end - start).count();

    // Sort the set and measure the time taken (sets are inherently sorted, so this is just a placeholder)
    sortRace.setTime = -1;

    results.push_back(sortRace);

    // RACE 3: INSERTION
    RaceResult insertRace;
    insertRace.operationName = "Insert";
    string targetStr = "TESTCODE";

    // Insert into vector and measure the time taken
    start = high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size() / 2, targetStr);
    end = high_resolution_clock::now();
    insertRace.vectorTime = duration_cast < nanoseconds > (end - start).count();

    // Insert into list and measure the time taken
    start = high_resolution_clock::now();
    auto listIt = lst.begin();
    advance(listIt, lst.size() / 2);
    lst.insert(listIt, targetStr);
    end = high_resolution_clock::now();
    insertRace.listTime = duration_cast < nanoseconds > (end - start).count();

    // Insert into set and measure the time taken
    start = high_resolution_clock::now();
    st.insert(targetStr);
    end = high_resolution_clock::now();
    insertRace.setTime = duration_cast < nanoseconds > (end - start).count();

    results.push_back(insertRace);

    // RACE 4: DELETION
    RaceResult deleteRace;
    deleteRace.operationName = "Delete";

    // Delete from vector and measure the time taken
    start = high_resolution_clock::now();
    vec.erase(vec.begin() + vec.size() / 2);
    end = high_resolution_clock::now();
    deleteRace.vectorTime = duration_cast < nanoseconds > (end - start).count();

    // Delete from list and measure the time taken
    start = high_resolution_clock::now();
    listIt = lst.begin();
    advance(listIt, lst.size() / 2);
    lst.erase(listIt);
    end = high_resolution_clock::now();
    deleteRace.listTime = duration_cast < nanoseconds > (end - start).count();

    // Delete from set and measure the time taken
    start = high_resolution_clock::now();
    auto setIt = st.begin();
    advance(setIt, st.size() / 2);
    st.erase(setIt);
    end = high_resolution_clock::now();
    deleteRace.setTime = duration_cast < nanoseconds > (end - start).count();

    results.push_back(deleteRace);

    // Display the results
    cout << "\n=======================================================\n";
    cout << "       DATA STRUCTURE RACES (in nanoseconds)\n";
    cout << "=======================================================\n";

    // Header
    cout << left << setw(12) << "Operation" <<
        right << setw(15) << "Vector" <<
        right << setw(15) << "List" <<
        right << setw(15) << "Set" << "\n";
    cout << string(57, '-') << "\n";

    // Display each race result
    for (const auto & race: results) {
        cout << left << setw(12) << race.operationName;

        // Vector time
        if (race.vectorTime == -1)
            cout << right << setw(15) << "N/A";
        else
            cout << right << setw(15) << race.vectorTime;

        // List time
        if (race.listTime == -1)
            cout << right << setw(15) << "N/A";
        else
            cout << right << setw(15) << race.listTime;

        // Set time
        if (race.setTime == -1)
            cout << right << setw(15) << "N/A";
        else
            cout << right << setw(15) << race.setTime;

        cout << "\n";
    }
    cout << "=======================================================\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/