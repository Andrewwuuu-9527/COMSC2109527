// COMSC-210 | Lab 14 | Andrew
#include <iostream>

#include <iomanip>

using namespace std;

const int W10 = 10;

// Color class, represents an RGB color with three private integer members
class Color {
    private: int red;
    int green;
    int blue;

    public:
        // Constructor: initialize all channels to 0
        Color(): red(0),
    green(0),
    blue(0) {}

    // Getters (marked const, they don't modify the object)
    int getRed() const {
        return red;
    }
    int getGreen() const {
        return green;
    }
    int getBlue() const {
        return blue;
    }

    // Setters (modify the object, no const)
    void setRed(int r) {
        red = r;
    }
    void setGreen(int g) {
        green = g;
    }
    void setBlue(int b) {
        blue = b;
    }

    // Print the color's RGB values in a nicely formatted way
    void print() const {
        cout << "RGB(" << setw(3) << red << ", " <<
            setw(3) << green << ", " <<
            setw(3) << blue << ")" << endl;
    }
};

int main() {
    cout << "===== Color Class Demo =====\n\n";

    // Object 1: red
    Color c1;
    c1.setRed(255);
    c1.setGreen(0);
    c1.setBlue(0);
    cout << "Color 1: ";
    c1.print();

    // Object 2: teal
    Color c2;
    c2.setRed(0);
    c2.setGreen(128);
    c2.setBlue(128);
    cout << "Color 2: ";
    c2.print();

    // Object 3: gold
    Color c3;
    c3.setRed(255);
    c3.setGreen(215);
    c3.setBlue(0);
    cout << "Color 3: ";
    c3.print();

    // Object 4: dark purple
    Color c4;
    c4.setRed(75);
    c4.setGreen(0);
    c4.setBlue(130);
    cout << "Color 4: ";
    c4.print();

    return 0;
}