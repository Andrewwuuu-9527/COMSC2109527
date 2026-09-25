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

    // Write sorted results to output file
    ofstream fout("210-lab-13-grades-sorted.txt");
    if (!fout) {
        cout << "Error: Cannot create output file '210-lab-13-grades-sorted.txt'.\n";
        return 1;
    }
    writeSorted(fout, students, count);
    fout.close();
    cout << "Sorted results written to 210-lab-13-grades-sorted.txt\n";

    // Display summary statistics
    displaySummary(students, count);

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

// Write sorted records to output file
void writeSorted(ofstream& fout, Student students[], int count) {
    for (int i = 0; i < count; i++) {
        fout << students[i].studentID << " " << students[i].examScore << "\n";
    }
}

// Display summary statistics to console
void displaySummary(Student students[], int count) {
    // Find min and max
    int minIdx = 0;
    int maxIdx = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].examScore < students[minIdx].examScore) minIdx = i;
        if (students[i].examScore > students[maxIdx].examScore) maxIdx = i;
    }

    // Calculate mean
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].examScore;
    }
    double mean = sum / count;

    // Create a copy sorted by score
    Student sortedByScore[MAX_STUDENTS];
    for (int i = 0; i < count; i++) sortedByScore[i] = students[i];

    for (int i = 0; i < count - 1; i++) {
        int smallestIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (sortedByScore[j].examScore < sortedByScore[smallestIndex].examScore) {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) {
            Student temp = sortedByScore[i];
            sortedByScore[i] = sortedByScore[smallestIndex];
            sortedByScore[smallestIndex] = temp;
        }
    }

    double medianScore;
    int medianID;
    if (count % 2 == 1) {
        medianScore = sortedByScore[count / 2].examScore;
        medianID = sortedByScore[count / 2].studentID;
    } else {
        medianScore = (sortedByScore[count / 2 - 1].examScore
                     + sortedByScore[count / 2].examScore) / 2.0;
        medianID = sortedByScore[count / 2].studentID;
    }

    // Standard deviation
    double sumSq = 0;
    for (int i = 0; i < count; i++) {
        double diff = students[i].examScore - mean;
        sumSq += diff * diff;
    }
    double stdDev = sqrt(sumSq / count);

    cout << "\n--- Summary Statistics ---\n";
    cout << "Minimum Score: " << students[minIdx].examScore
         << " (Student ID: " << students[minIdx].studentID << ")\n";
    cout << "Maximum Score: " << students[maxIdx].examScore
         << " (Student ID: " << students[maxIdx].studentID << ")\n";
    cout << "Mean Score: " << mean << "\n";
    cout << "Median Score: " << medianScore
         << " (Student ID: " << medianID << ")\n";
    cout << "Standard Deviation: " << stdDev << "\n";
}