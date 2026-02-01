

// This program will take three numbers as input and will output the largest number among them


#include <iostream>
using namespace std;


int main() {

    int num1, num2, num3;

<<<<<<< HEAD
    string space(3, ' ');

    cout << space << "=========================================" << space << "\n"; // Creating an upper border
    cout << space << "||" << space << " WELCOME TO NUMBER COMPARATOR! " << space << "||" << "\n";
    cout << space << "=========================================" << space << "\n\n\n";
=======
>>>>>>> e849f311b218bad6c405d6b511f96e93683b20ab

    cout << "Enter three numbers (seperated by spaces): ";
    cin >> num1 >> num2 >> num3;

<<<<<<< HEAD
    cout << "\n\n";


    // using nested if-else statement to check the largest number among the input
    if (num1 >= num2 && num1 >= num3) {
        cout << num1 << " is the largest number." << "\n\n";

    }
    else if (num2 >= num1 && num2 >= num3) {
        cout << num2 << " is the largest number." << "\n\n";

    }
    else {
        cout << num3 << " is the largest number." << "\n\n";

    }



    cout << space << "...Exiting the program. See you again!" << "\n" << endl;

=======

    // using nested if-else statement to check the largest number among the input
    if (num1 >= num2 && num1 >= num3) {
        cout << num1 << " is the largest number." << endl;

    }
    else if (num2 >= num1 && num2 >= num3) {
        cout << num2 << " is the largest number." << endl;

    }
    else {
        cout << num3 << " is the largest number." << endl;

    }
>>>>>>> e849f311b218bad6c405d6b511f96e93683b20ab
    return 0;


}