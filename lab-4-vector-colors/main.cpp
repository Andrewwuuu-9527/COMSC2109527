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
    
    Color testColor = {100, 150, 200};
    cout << "Test Color - R: " << testColor.red
         << " G: " << testColor.green
         << " B: " << testColor.blue << endl;

    return 0;
}