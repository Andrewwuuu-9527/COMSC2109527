// COMSC-210 | Lab 7 | Andrew
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5; // Size of the array    

// Function prototypes
string* reverseArray(string *arr, int size);
void displayArray(string *arr, int size);

int main() {
    string *arr = new string[SIZE];



    delete[] arr;
    return 0;
}