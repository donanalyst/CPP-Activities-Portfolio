#include <iostream>
using namespace std;


int main() {
    int num; // Variable for the number

    string border(34, '='); // Border for the title
    string space(7, ' '); // Space for the title

    cout << border << "\n";
    cout << space << "PRINT NUMBERS 1 TO N" << "\n";
    cout << border << "\n\n";

    cout << "Enter a number (N): ";
    cin >> num;

    cout << "\n\n";

    cout << "[OUTPUT]" << "\n";
    for (int i = 1; i <= num; i++)
    {
        cout << i << " ";
    }


    // Displaying the pattern

    cout << "\n\n" << border << "\n";
    cout << space << "* * PATTERN DISPLAY * *" << "\n";
    cout << border << "\n\n";

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++) // Using a Nested for Loop to print the pattern
        {
            cout << j << " ";
        }
        cout << "\n";
    }


    cout << "\n\nPrinted " << num << " numbers successfully!" << "\n" << endl;

    return 0;
}