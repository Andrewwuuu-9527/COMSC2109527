// COMSC-210 | Lab 6 | Andrew
#include <iostream>

using namespace std;

const int SIZE = 5; // Size of the dynamic array

// Function prototypes
void enterArrayData(double * arr, int size);
void outputArrayData(double * arr, int size);
double sumArray(double * arr, int size);

int main() {
    double * arr = new double[SIZE];

    enterArrayData(arr, SIZE);
    outputArrayData(arr, SIZE);

    double total = sumArray(arr, SIZE);
    cout << "Sum of values: " << total << endl;

    delete[] arr;
    return 0;
}

// Function to enter data into the array
void enterArrayData(double * arr, int size) {
    cout << "Data entry for the array:\n";
    for (int i = 0; i < size; i++) {
        cout << "> Element #" << i << ": ";
        cin >> * (arr + i);
    }
    cout << "Data entry complete.\n";
}

// Function to output the array data
void outputArrayData(double * arr, int size) {
    cout << "Outputting array elements: ";
    for (int i = 0; i < size; i++) {
        cout << * (arr + i) << " ";
    }
    cout << endl;
}

// Function to calculate the sum of the array elements
double sumArray(double * arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += * (arr + i);
    }
    return sum;
}