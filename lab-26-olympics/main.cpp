// COMSC-210 | Lab 26 | Andrew
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

int main() {
    const int NUM_SIMULATIONS = 15;

    // 3D array to store times for each operation and data structure
    long long times[2][4][3] = {0};

    // Read data from file into a vector
    vector<string> rawData;
    ifstream fin("codes.txt");
    if (!fin) {
        cout << "Error: Cannot open codes.txt\n";
        return 1;
    }
    string line;
    while (fin >> line) {
        rawData.push_back(line);
    }
    fin.close();

    // Perform simulations
    for (int sim = 0; sim < NUM_SIMULATIONS; sim++) {
        vector<string> vec;
        list<string> lst;
        set<string> st;
        
        // RACE 1: READING
        auto start = high_resolution_clock::now();
        for (const string& s : rawData) vec.push_back(s);
        auto end = high_resolution_clock::now();
        times[0][0][0] = duration_cast<nanoseconds>(end - start).count();
        times[1][0][0] += times[0][0][0];

        start = high_resolution_clock::now();
        for (const string& s : rawData) lst.push_back(s);
        end = high_resolution_clock::now();
        times[0][0][1] = duration_cast<nanoseconds>(end - start).count();
        times[1][0][1] += times[0][0][1];

        start = high_resolution_clock::now();
        for (const string& s : rawData) st.insert(s);
        end = high_resolution_clock::now();
        times[0][0][2] = duration_cast<nanoseconds>(end - start).count();
        times[1][0][2] += times[0][0][2];

        // RACE 2: SORTING 
        start = high_resolution_clock::now();
        sort(vec.begin(), vec.end());
        end = high_resolution_clock::now();
        times[0][1][0] = duration_cast<nanoseconds>(end - start).count();
        times[1][1][0] += times[0][1][0];

        start = high_resolution_clock::now();
        lst.sort();
        end = high_resolution_clock::now();
        times[0][1][1] = duration_cast<nanoseconds>(end - start).count();
        times[1][1][1] += times[0][1][1];

        times[0][1][2] = 0; 
        times[1][1][2] += 0;

        // RACE 3: INSERTING
        string targetStr = "TESTCODE";
        start = high_resolution_clock::now();
        vec.insert(vec.begin() + vec.size() / 2, targetStr);
        end = high_resolution_clock::now();
        times[0][2][0] = duration_cast<nanoseconds>(end - start).count();
        times[1][2][0] += times[0][2][0];

        start = high_resolution_clock::now();
        auto listIt = lst.begin();
        advance(listIt, lst.size() / 2);
        lst.insert(listIt, targetStr);
        end = high_resolution_clock::now();
        times[0][2][1] = duration_cast<nanoseconds>(end - start).count();
        times[1][2][1] += times[0][2][1];

        start = high_resolution_clock::now();
        st.insert(targetStr);
        end = high_resolution_clock::now();
        times[0][2][2] = duration_cast<nanoseconds>(end - start).count();
        times[1][2][2] += times[0][2][2];

        // RACE 4: DELETING
        start = high_resolution_clock::now();
        vec.erase(vec.begin() + vec.size() / 2);
        end = high_resolution_clock::now();
        times[0][3][0] = duration_cast<nanoseconds>(end - start).count();
        times[1][3][0] += times[0][3][0];

        start = high_resolution_clock::now();
        listIt = lst.begin();
        advance(listIt, lst.size() / 2);
        lst.erase(listIt);
        end = high_resolution_clock::now();
        times[0][3][1] = duration_cast<nanoseconds>(end - start).count();
        times[1][3][1] += times[0][3][1];

        start = high_resolution_clock::now();
        auto setIt = st.begin();
        advance(setIt, st.size() / 2);
        st.erase(setIt);
        end = high_resolution_clock::now();
        times[0][3][2] = duration_cast<nanoseconds>(end - start).count();
        times[1][3][2] += times[0][3][2];
    }

    // Output results 
    cout << "Number of simulations: " << NUM_SIMULATIONS << "\n";
    cout << "Last run Read (Vector): " << times[0][0][0] << " ns\n";
    cout << "Last run Sort (Vector): " << times[0][1][0] << " ns\n";

    return 0;
}