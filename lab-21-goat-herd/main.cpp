// COMSC-210 | Lab 21 | Andrew
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_NAMES = 15;
const int NUM_COLORS = 15;
const int MIN_AGE = 1;
const int MAX_AGE = 20;
const int MIN_GOATS = 5;
const int MAX_GOATS = 20;

class Goat {
private:
    int age;
    string name;
    string color;
    string names[NUM_NAMES] = {
        "Senior", "Godlike", "Old", "Mature", "Teen",
        "Young", "Kid", "Baby", "Elder", "Ancient",
        "Legendary", "Heroic", "Mystic", "Wise", "Swift"
    };
    string colors[NUM_COLORS] = {
        "Yellow", "Red", "Gold", "Mauve", "White",
        "Black", "Brown", "Gray", "Blue", "Green",
        "Orange", "Pink", "Purple", "Silver", "Cyan"
    };

public:
    Goat();
    Goat(int a, string n, string c);
    int getAge() const;
    string getName() const;
    string getColor() const;
    void print() const;
};


int main() {

    return 0;
}

// Default constructor: random age (1-20), random name, random color
Goat::Goat() {
    age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
    name = names[rand() % NUM_NAMES];
    color = colors[rand() % NUM_COLORS];
}

// Parameter constructor: explicit age, name, color
Goat::Goat(int a, string n, string c) {
    age = a;
    name = n;
    color = c;
}

int Goat::getAge() const { return age; }
string Goat::getName() const { return name; }
string Goat::getColor() const { return color; }

// print() outputs the goat's info in the format "name (color, age)"
void Goat::print() const {
    cout << "    " << name << " (" << color << ", " << age << ")" << endl;
}