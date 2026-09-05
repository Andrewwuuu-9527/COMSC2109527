// COMSC-210 | Lab 4 | Andrew
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct Color {
    int red;
    int green;
    int blue;
};

int main() {

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    const int MIN_N = 25;
    const int MAX_N = 50;
    const int MIN_RBG = 0;
    const int MAX_RBG = 255;

    int n = rand() % (MAX_N - MIN_N + 1) + MIN_N; // Random number of colors between MIN_N and MAX_N
    vector<Color> colors(n); // Create a vector of Color structs with size n

    // Generate random colors and store them in the vector
    for (int i = 0; i < n; ++i) {
        Color temp;
        temp.red = rand() % (MAX_RBG - MIN_RBG + 1) + MIN_RBG;
        temp.green = rand() % (MAX_RBG - MIN_RBG + 1) + MIN_RBG;
        temp.blue = rand() % (MAX_RBG - MIN_RBG + 1) + MIN_RBG;
        colors.push_back(temp);
    }

    // Output the generated colors
    cout << "Generated " << colors.size() << " random color(s)." << endl;
    for (size_t i = 0; i < colors.size(); ++i) {
        cout << "Color " << i + 1 << ": R=" << colors[i].red
             << " G=" << colors[i].green
             << " B=" << colors[i].blue << endl;
    }

    return 0;
}