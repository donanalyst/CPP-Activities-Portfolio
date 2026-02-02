#include <iostream>
#include <vector>
using namespace std;


int main() {


    vector<int> listFactorial; // 

    int num, result = 1; // Variable for the number and the result

    string border(36, '-'); // Creatomg borders and space 
    string border2(25, '_');
    string space(7, ' ');


    // Header of the program and the title
    cout << border << "\n";
    cout << space << "FACTORIAL CALCULATOR" << "\n";
    cout << border << "\n\n";


    cout << "Enter a number: "; // asked the user input 
    cin >> num;
    cout << "\n\n";


    // Another header for the visualization of the calculation steps
    cout << "[CALCULATION STEPS]" << "\n\n";

    cout << num << "!  = ";


    // Started an if Statement to control the user input value to less than or equal to 10
    if (num > 10) 
    {   
        for (int d = 5; d > 0; d--)
        {
            for (int i = 0; i < d; i++) 
            {
                cout << " - ";
            }
            cout << "\n" << "    = ";
        }
        cout << "\n\n" << "[WARNING]" << "\n";

        cout << "The maximum safe input is 10." << endl;

    }


    // An else statement that will output the calculation steps
    else 

    {   
        // Initial for loop for storing the value to the vector list
        for (int i = num; i > 0; i--)
        {   
        
            listFactorial.push_back(i);
        
        }
        
        // Another for loop to print out the value line by line based on the user's number input
        for (int i = 0; i < num; i++)
        {
        
        
            int op = listFactorial.size() - 1;
            int refIndex = op;


            // An Inner for loop to include the operator 'x' after printing each of the value inside the vector list
            for (auto n : listFactorial )
            {
                cout << n;
                if (refIndex > 0) cout << " x ";

                refIndex = refIndex - 1;

            }

            // An if Statement to check if the size of the vector list is only '1' to exit from the for loop
            if (listFactorial.size() == 1)
            {   

                cout << "\n\n";
                result = result * listFactorial[0]; // Multiplying the result value and the first vector list and assigning ito the result variable
                break; // exiting the for loop

            } 

            // if the above if Statement is false, this will process to combine the value of the first two value inside the vector list
            else 

            {
                int firstNumber = listFactorial[0];
                int secondNumber = listFactorial[1];
                int combine = firstNumber * secondNumber; // multiplying the first two value to each other and stored the value inside the 'combine' variable

                cout << "\n" << "    = "; // adding a new line and printing the '=' sign before printing the next output value inside the vector list

                listFactorial.erase(listFactorial.begin(), listFactorial.begin() + 2); // removing the first two value 
                listFactorial.insert(listFactorial.begin(), combine); // Adding the value of the 'combine' variable to the beginning of the list 
            }
        }

    }

    cout << "\n\n" << border2 << "\n";
    cout << "RESULT: " << num << "! = ";
    if (num <= 10) cout << result; // using if statement to print out the value inside the result variable 
    cout << "\n" << endl;

    return 0;
}