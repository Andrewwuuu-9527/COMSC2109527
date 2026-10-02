// COMSC-210 | Lab 16 | Andrew
#include <iostream>
using namespace std;

class Color {
private:
    int red;
    int green;
    int blue;

public:
    // Default constructor: initializes all values to 0
    Color() {
        red = 0;
        green = 0;
        blue = 0;
    }

    // Display the color in RGB format
    void display() const {
        cout << "RGB(" << red << ", " << green << ", " << blue << ")" << endl;
    }
};

int main() {
    // Test default constructor
    Color defaultColor;
    cout << "Default color: ";
    defaultColor.display();

    return 0;
}