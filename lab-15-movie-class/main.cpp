// COMSC-210 | Lab 15 | Andrew
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Movie class, represents a movie: title, year released, and screenwriter
class Movie {
private:
    string title;
    int yearReleased;
    string screenwriter;

public:
    // Default constructor: initialize members to empty values
    Movie() : title(""), yearReleased(0), screenwriter("") {}

    // Getters
    string getTitle() const        { return title; }
    int getYearReleased() const    { return yearReleased; }
    string getScreenwriter() const { return screenwriter; }

    // Setters
    void setTitle(string t)        { title = t; }
    void setYearReleased(int y)    { yearReleased = y; }
    void setScreenwriter(string s) { screenwriter = s; }

    // Print object data in the format required by the sample output
    void print() const {
        cout << "Movie: " << screenwriter << endl;
        cout << "   Year released: " << yearReleased << endl;
        cout << "   Screenwriter: " << title << endl;
        cout << endl;
    }
};

int main() {

    return 0;
}