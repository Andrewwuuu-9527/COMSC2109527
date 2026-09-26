// COMSC-210 | Lab 14 | Andrew
#include <iostream>
#include <iomanip>
using namespace std;

// Color class, represents an RGB color with three private integer members
class Color {
private:
    int red;
    int green;
    int blue;

public:
    // Constructor: initialize all channels to 0
    Color() : red(0), green(0), blue(0) {}

    // Getters (marked const, they don't modify the object)
    int getRed() const   { return red; }
    int getGreen() const { return green; }
    int getBlue() const  { return blue; }

    // Setters (modify the object, no const)
    void setRed(int r)   { red = r; }
    void setGreen(int g) { green = g; }
    void setBlue(int b)  { blue = b; }
};

int main() {

    return 0;
}