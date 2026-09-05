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

    vector<Color> colors;
    Color temp = {200, 100, 50};
    colors.push_back(temp);

    cout << "Vector contains " << colors.size() << " color(s)." << endl;
    for (size_t i = 0; i < colors.size(); ++i) {
        cout << "Color " << i + 1 << ": R=" << colors[i].red
             << " G=" << colors[i].green
             << " B=" << colors[i].blue << endl;
    }

    return 0;
}