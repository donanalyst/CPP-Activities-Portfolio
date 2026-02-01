

// This program will take three numbers as input and will output the largest number among them


#include <iostream>
using namespace std;


int main() {

    int num1, num2, num3;


    cout << "Enter three numbers (seperated by spaces): ";
    cin >> num1 >> num2 >> num3;


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
    return 0;


}