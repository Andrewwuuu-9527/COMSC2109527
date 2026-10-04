// COMSC-210 | Lab 18 | Andrew
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int MIN_TENTHS = 10;
const int MAX_TENTHS = 50;
const int RATING_RANGE = MAX_TENTHS - MIN_TENTHS + 1;

// Review node in the linked list
struct Review {
    double rating;
    string comment;
    Review* next;
};

class Movie {
private:
    string title;
    Review* head;

public:
    // Constructors
    Movie();
    Movie(string t);

    // Rule of Three
    ~Movie();
    Movie(const Movie& other);
    Movie& operator=(const Movie& other);

    // Methods
    void addReview(double rating, string comment);
    void displayReviews() const;
    string getTitle() const { return title; }
};

// Default constructor: empty title, empty list
Movie::Movie() {
    title = "Unknown";
    head = nullptr;
}

// Parameter constructor: given title, empty list
Movie::Movie(string t) {
    title = t;
    head = nullptr;
}

int main() {

    return 0;
}