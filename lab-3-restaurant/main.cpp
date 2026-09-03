// COMSC-210 | Lab 3 | Andrew
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Restaurant{
    string name;
    string address;
    int rating;
    double avgPrice;
    bool hasDelivery;
};

Restaurant populateRestaurant();
void displayRestaurant(const Restaurant &r);

int main(){

    return 0;
}