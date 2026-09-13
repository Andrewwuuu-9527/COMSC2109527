// COMSC-210 | Lab 7 | Andrew
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

int main() {
    string *arr = new string[SIZE];



    delete[] arr;
    return 0;
}