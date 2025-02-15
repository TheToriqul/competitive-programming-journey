#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Cars {
    char type;
    int seatingCapacity;
    int mpg;
    double price;
    string color;
};

int main() {
    ifstream inFile("CarLot.txt");
    if(!inFile) {
        cout << "\n================================================" << endl;
        cout << "❌ Error: CarLot.txt file not found!" << endl;
        cout << "   Please contact our manager at toriq@CarLot.com for assistance" << endl;
        cout << "================================================" << endl;
        return 1;
    }

    Cars userCar;
    Cars inventoryCar;
    char searchChoice;
    int matchCount = 0;
    
    cout << "\n================================================" << endl;
    cout << "🚗 Welcome to Car Lot Search System" << endl;
    cout << "================================================" << endl;
    
    cout << "\nEnter the car type (C for Coupe, M for Minivan, S for SUV): ";
    cin >> userCar.type;
    
    cout << "Enter the seating capacity: ";
    cin >> userCar.seatingCapacity;
    
    cout << "Enter the price: ";
    cin >> userCar.price;
    
    cout << "Enter the mpg: ";
    cin >> userCar.mpg;
    
    cout << "Enter the color: ";
    cin >> userCar.color;
    
    cout << "Do you want to search for an exact match (E) or cars with some matching specifications (M)? ";
    cin >> searchChoice;

    cout << "\nSearch Results:" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Type Seats MPG Price Color" << endl;
    cout << "------------------------------------------------" << endl;

    bool foundMatch = false;
    
    while(inFile >> inventoryCar.type >> 
                   inventoryCar.seatingCapacity >> 
                   inventoryCar.mpg >> 
                   inventoryCar.price >> 
                   inventoryCar.color) {
        
        if(toupper(searchChoice) == 'E') {
            if(toupper(inventoryCar.type) == toupper(userCar.type) &&
               inventoryCar.seatingCapacity == userCar.seatingCapacity &&
               inventoryCar.mpg == userCar.mpg &&
               inventoryCar.price == userCar.price &&
               inventoryCar.color == userCar.color) {
                   
                cout << "  " << inventoryCar.type << "    "
                     << inventoryCar.seatingCapacity << "     "
                     << inventoryCar.mpg << "   "
                     << inventoryCar.price << "  "
                     << inventoryCar.color << endl;
                foundMatch = true;
                matchCount++;
            }
        }
        else if(toupper(searchChoice) == 'M') {
            // Only show cars of the same type as user input
            if(toupper(inventoryCar.type) == toupper(userCar.type)) {
                cout << "  " << inventoryCar.type << "    "
                     << inventoryCar.seatingCapacity << "     "
                     << inventoryCar.mpg << "   "
                     << inventoryCar.price << "  "
                     << inventoryCar.color << endl;
                foundMatch = true;
                matchCount++;
            }
        }
    }
    
    cout << "------------------------------------------------" << endl;
    
    cout << "\n================================================" << endl;
    if(!foundMatch) {
        cout << "😔 Sorry, no cars matching your specifications were found." << endl;
    } else {
        cout << "✨ Search complete! Found " << matchCount << " matching car(s)." << endl;
    }
    cout << "================================================" << endl;
    
    cout << "\n👋 Thank you for using our Car Lot Search System!" << endl;
    cout << "================================================" << endl;
    
    inFile.close();
    return 0;
}