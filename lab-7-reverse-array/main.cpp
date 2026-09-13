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

    // Initialize the array with some values
    *(arr + 0) = "Janet";
    *(arr + 1) = "Jeffe";
    *(arr + 2) = "Jin";
    *(arr + 3) = "Joe";
    *(arr + 4) = "Junio";

    // Display the original array
    cout << "Original array: ";
    displayArray(arr, SIZE);

    // Reverse the array
    arr = reverseArray(arr, SIZE);

    // Display the reversed array
    cout << "Reversed array: ";
    displayArray(arr, SIZE);

    delete[] arr;
    return 0;
}

// Function to reverse the array
void displayArray(string *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

// Function to reverse the array
string* reverseArray(string *arr, int size) {
    int left = 0;
    int right = size - 1;

    // Swap elements from both ends of the array until the middle is reached
    while (left < right) {
        string temp = *(arr + left);
        *(arr + left) = *(arr + right);
        *(arr + right) = temp;

        left++;
        right--;
    } 
    return arr;
}