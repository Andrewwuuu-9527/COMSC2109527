// COMSC-210 | Lab 6 | Andrew
#include <iostream>
using namespace std;

const int SIZE = 5;

int main() {
    double *arr = new double[SIZE];


    delete[] arr;
    return 0;
}