// COMSC-210 | Lab 4 | Andrew
#include <iostream>

#include <vector>

#include <cstdlib>

#include <ctime>

#include <iomanip>

using namespace std;

// Define a struct to hold RGB color values
struct Color {
    int red;
    int green;
    int blue;
};

int main() {

    srand(static_cast < unsigned int > (time(0))); // Seed the random number generator

    const int MIN_N = 25;
    const int MAX_N = 50;
    const int MIN_RBG = 0;
    const int MAX_RBG = 255;

    int n = rand() % (MAX_N - MIN_N + 1) + MIN_N; // Random number of colors between MIN_N and MAX_N
    vector < Color > colors(n); // Create a vector of Color structs with size n

    // Generate random colors and store them in the vector
    for (int i = 0; i < n; ++i) {
        Color temp;
        temp.red = rand() % (MAX_RBG - MIN_RBG + 1) + MIN_RBG;
        temp.green = rand() % (MAX_RBG - MIN_RBG + 1) + MIN_RBG;
        temp.blue = rand() % (MAX_RBG - MIN_RBG + 1) + MIN_RBG;
        colors.push_back(temp);
    }

    // Print the header for the output table
    cout << left << setw(10) << "Color #" <<
        right << setw(10) << "R value" <<
        setw(10) << "G value" <<
        setw(10) << "B value" << endl;

    cout << string(40, '-') << endl; // Print a separator line

    // Print the color values in a formatted table
    for (size_t i = 0; i < colors.size(); ++i) {
        cout << left << setw(10) << (i + 1) <<
            right << setw(10) << colors[i].red <<
            setw(10) << colors[i].green <<
            setw(10) << colors[i].blue << endl;
    }

    return 0;
}