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


    delete[] arr;
    return 0;
}