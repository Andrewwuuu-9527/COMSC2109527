// COMSC-210 | Lab 15 | Andrew
#include <iostream>

#include <fstream>

#include <iomanip>

#include <vector>

#include <string>

using namespace std;

// Movie class, represents a movie: title, year released, and screenwriter
class Movie {
    private: string title;
    int yearReleased;
    string screenwriter;

    public:
        // Default constructor: initialize members to empty values
        Movie(): title(""),
    yearReleased(0),
    screenwriter("") {}

    // Getters
    string getTitle() const {
        return title;
    }
    int getYearReleased() const {
        return yearReleased;
    }
    string getScreenwriter() const {
        return screenwriter;
    }

    // Setters
    void setTitle(string t) {
        title = t;
    }
    void setYearReleased(int y) {
        yearReleased = y;
    }
    void setScreenwriter(string s) {
        screenwriter = s;
    }

    // Print object data in the format required by the sample output
    void print() const {
        cout << "Movie: " << screenwriter << endl;
        cout << "   Year released: " << yearReleased << endl;
        cout << "   Screenwriter: " << title << endl;
        cout << endl;
    }
};

int main() {
    vector < Movie > movies;

    // Open input file and verify
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Error: Cannot open input file 'input.txt'.\n";
        cout << "Please ensure the file exists in the program directory.\n";
        return 1;
    }

    // Read 4 records
    const int NUM_RECORDS = 4;
    for (int i = 0; i < NUM_RECORDS; i++) {
        Movie temp; // temporary Movie object
        string inTitle;
        int inYear;
        string inScreenwriter;

        // Read data in the order: title, year, screenwriter
        getline(fin, inTitle);
        fin >> inYear;
        fin.ignore(); // clear newline before reading next string
        getline(fin, inScreenwriter);

        // Populate temporary object with setters
        temp.setTitle(inTitle);
        temp.setYearReleased(inYear);
        temp.setScreenwriter(inScreenwriter);

        // Append to the container
        movies.push_back(temp);
    }
    fin.close();

    // Output all movies
    for (const Movie & m: movies) {
        m.print();
    }

    return 0;
}