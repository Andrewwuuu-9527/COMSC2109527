// COMSC-210 | Lab 6 | Andrew
#include <iostream>
using namespace std;

const int SIZE = 5; // Size of the dynamic array

// Function prototypes
void enterArrayData(double *arr, int size);
void outputArrayData(double *arr, int size);
void sumArry(double *arr, int size);

int main() {
    double *arr = new double[SIZE];

    enterArrayData(arr, SIZE);

    delete[] arr;
    return 0;
}

// Function to enter data into the array
void enterArrayData(double *arr, int size) {
    cout << "Data entry for the array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter value for element " << i << ": ";
        cin >> *(arr + i);
    }
    cout << "Data entry complete.\n";
}