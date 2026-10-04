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

// Destructor: delete all nodes in the linked list
Movie::~Movie() {
    Review* current = head;
    while (current) {
        Review* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

// addReview() inserts a new review at the head of the list
void Movie::addReview(double rating, string comment) {
    Review* newNode = new Review;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    head = newNode;
}

// displayReviews() traverses the list, prints title, each review, and average
void Movie::displayReviews() const {
    cout << "Movie Title: " << title << endl;

    if (head == nullptr) {
        cout << "  No reviews.\n";
        return;
    }

    double sum = 0;
    int count = 0;
    Review* current = head;
    while (current) {
        count++;
        sum += current->rating;
        cout << "  > Review #" << count << ": "
             << fixed << setprecision(1) << current->rating
             << ": " << current->comment << endl;
        current = current->next;
    }
    cout << "  > Average: " << fixed << setprecision(1)
         << (sum / count) << endl;
}

// Copy constructor: deep copies the entire linked list
Movie::Movie(const Movie& other) {
    title = other.title;
    head = nullptr;

    if (other.head == nullptr) return;

    // Copy first node
    head = new Review;
    head->rating = other.head->rating;
    head->comment = other.head->comment;
    head->next = nullptr;

    // Copy remaining nodes
    Review* current = head;
    Review* otherCurrent = other.head->next;
    while (otherCurrent) {
        Review* newNode = new Review;
        newNode->rating = otherCurrent->rating;
        newNode->comment = otherCurrent->comment;
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
        otherCurrent = otherCurrent->next;
    }
}

// Copy assignment operator: frees existing list, then deep copies
Movie& Movie::operator=(const Movie& other) {
    if (this == &other) return *this;  // self-assignment check

    // Free existing reviews
    Review* current = head;
    while (current) {
        Review* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    title = other.title;

    if (other.head == nullptr) return *this;

    // Deep copy
    head = new Review;
    head->rating = other.head->rating;
    head->comment = other.head->comment;
    head->next = nullptr;

    current = head;
    Review* otherCurrent = other.head->next;
    while (otherCurrent) {
        Review* newNode = new Review;
        newNode->rating = otherCurrent->rating;
        newNode->comment = otherCurrent->comment;
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
        otherCurrent = otherCurrent->next;
    }

    return *this;
}