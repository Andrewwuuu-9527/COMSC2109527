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

    cout << "Read " << count << " temperatures from file.\n";

    return 0;
}