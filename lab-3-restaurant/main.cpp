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

    cout << "\n--- Test: Single Restaurant (with display function) ---\n";
    displayRestaurant(testRestaurant);

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

void displayRestaurant(const Restaurant &r){
    cout << " Name: " << r.name << endl;
    cout << " Address: " << r.address << endl;
    cout << " Rating: " << r.rating << "/5" << endl;
    cout << " Avg Price: $" << fixed << setprecision(2) << r.avgPrice << endl;
    cout << " Delivery: " << (r.hasDelivery ? "Yes" : "No") << endl;
}