

// This program will take three numbers as input and will output the largest number among them


#include <iostream>
using namespace std;


int main() {

    int num1, num2, num3;

    string space(3, ' ');

    cout << space << "=========================================" << space << "\n"; // Creating an upper border
    cout << space << "||" << space << " WELCOME TO NUMBER COMPARATOR! " << space << "||" << "\n";
    cout << space << "=========================================" << space << "\n\n\n";

    cout << "Enter three numbers (seperated by spaces): ";
    cin >> num1 >> num2 >> num3;

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

    return 0;


}