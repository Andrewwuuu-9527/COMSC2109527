// COMSC-210 | Lab 13 | Andrew
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_STUDENTS = 200;

struct Student {
    int studentID;
    double examScore;
};

// Function prototypes
int readStudents(ifstream& fin, Student students[]);
void selectionSort(Student students[], int count);
void writeSorted(ofstream& fout, Student students[], int count);
void displaySummary(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;

    // Read input file
    ifstream fin("210-lab-13-grades.txt");
    if (!fin) {
        cout << "Error: Cannot open input file '210-lab-13-grades.txt'.\n";
        cout << "Please ensure the file exists in the program directory.\n";
        return 1;
    }

    count = readStudents(fin, students);
    fin.close();
    cout << "Read " << count << " student records\n";

    if (count == 0) {
        cout << "No records found. Exiting.\n";
        return 1;
    }

    return 0;
}

// Read all student records from file into array
int readStudents(ifstream& fin, Student students[]) {
    int count = 0;
    while (count < MAX_STUDENTS && fin >> students[count].studentID
           >> students[count].examScore) {
        count++;
    }
    return count;
}