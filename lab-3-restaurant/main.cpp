// COMSC-210 | Lab 3 | Andrew
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
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

    Restaurant testRestaurant = populateRestaurant();

    cout << "\n--- Test: Single Restaurant Filled ---\n";
    cout << "Name: " << testRestaurant.name << endl;
    cout << "Address: " << testRestaurant.address << endl;
    cout << "Rating: " << testRestaurant.rating << endl;
    cout << "Price: " << testRestaurant.avgPrice << endl;
    cout << "Has Delivery: " << (testRestaurant.hasDelivery ? "Yes" : "No") << endl;

    return 0;
}

Restaurant populateRestaurant(){
    Restaurant temp;

    cout << "Enter restaurant name: ";
    getline(cin, temp.name);

    cout << "Enter restaurant address: ";
    getline(cin, temp.address);

    cout << "Enter restaurant rating (1-5): ";
    cin >> temp.rating;
    cin.ignore(); 
    while(temp.rating < 1 || temp.rating > 5){
        cout << "Invalid. Please enter a rating between 1 and 5: ";
        cin >> temp.rating;
    }

    cout << "Enter average price: $";
    cin >> temp.avgPrice;
    cin.ignore();

    char deliveryInput;
    cout << "Has delivery service? (Y/N): ";
    cin >> deliveryInput;
    temp.hasDelivery = (toupper(deliveryInput) == 'Y');

    cin.ignore();
    
    return temp;
}