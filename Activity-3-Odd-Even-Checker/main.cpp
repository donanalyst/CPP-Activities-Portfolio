// ACTIVITY 3: Odd or Even Checker 
// This is a program to check wether if a number is an ODD or Even

#include <iostream>
#include <limits> // Using limits for the stramsize and max() function from the  limits library
using namespace std;


int main() {
    int x;

    bool validInput = false; // This is for Input validation if user did not enter the correct data type

    string space(3, ' '); // Creating Space Border


    cout << space << "==============================================" << space << "\n"; // Creating an upper border
    cout << space << "||" << space << " WELCOME TO THE ODD OR EVEN CHECKER " << space << "||" << "\n";
    cout << space << "==============================================" << space << "\n";
    cout << "\n\n";

    cout << space << "--------------------------" << "\n";
    cout << space << "Please enter the number: ";






    // Keep asking until valid input
    while (!validInput) {
        if (cin >> x) { // Check if input is a number   
            cout << space << "--------------------------";
            cout << "\n\n";
            validInput = true;  // Success!

        }
        else {
            cout << space << "--------------------------" << "\n";
            cout << space << "Invalid input! Please enter a NUMBER: ";

            // Clear error state
            cin.clear();

            // Discard invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    // Check if the number is odd or even by using modulo operator
    if (x % 2 == 0) {
        cout << space << "--------------------------" << "\n";  //print if even result
        cout << space << "Number " << x << " is an Even Number\n";
        cout << space << "--------------------------"<< "\n\n";

        cout << endl;
    }
    else {
        cout << space << "--------------------------" << "\n";   //print if odd result
        cout << space << "Number " << x << " is an Odd Number\n";
        cout << space << "--------------------------" << "\n\n";

        cout << endl;
    }

    return 0;

}