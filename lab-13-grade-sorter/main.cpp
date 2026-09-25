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
        return 1;
    }

    count = readStudents(fin, students);
    fin.close();
    cout << "Read " << count << " student records\n";

    if (count == 0) return 1;

    // Sort by student ID
    selectionSort(students, count);

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

// Sort students by student ID in ascending order
void selectionSort(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int smallestIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j].studentID < students[smallestIndex].studentID) {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) {
            Student temp = students[i];
            students[i] = students[smallestIndex];
            students[smallestIndex] = temp;
        }
    }
}
