#include "studentList.h"  // Include necessary header files for various functionalities
#include "utils.h"
#include <iostream>      // For basic input/output operations
#include <vector>        // For using vector container
#include <limits>        // For numeric_limits (used in input validation)
#include <list>          // For list container (though not used in current code)
#include <fstream>       // For file handling (reading and writing to file)
#include <string>        // For string class
#include <sstream>       // For string streams (parsing strings)
#include <iterator>
    // For iterators (though not directly used)

// Using standard namespace to avoid prepending std:: to every standard function/object
using namespace std;




// Function prototypes (declared before main, defined after)
void viewHighScore(StudentList& list);  // Display high scores
void startQuiz(StudentList& list);      // Start quiz process
void viewMyProfile(StudentList& list);
void deleteMyProfile(StudentList& list);




// Main function - program entry point
int main() {
    // Create decorative borders for UI
    string border(36, '=');  // String of 36 '=' characters
    string space(6, ' ');    // String of 6 space characters

    StudentList list;  // Create studentList object to manage students

    StudentList archStudent;
    
    list.loadFromFile("../data/archiveInfo.csv");
    list.loadFromFile("../data/studentInfo.csv");

    // Display program header
    cout << border << "\n";
    cout << space << "C++ PROGRAMMING QUIZ" << "\n";
    cout << border << "\n\n";

    int choice;  // Variable to store user's menu choice
    
    // Main program loop - continues until user chooses to exit
    do {
        // Display menu options
        cout << "[1] Start Quiz" << "\n";
        cout << "[2] View High Scores" << "\n";
        cout << "[3] Instructions" << "\n";
        cout << "[4] Credits" << "\n";
        cout << "[5] View my Profile" << "\n";
        cout << "[6] Delete my Profile" << "\n";
        cout << "[0] Exit" << "\n";
        cout << "Enter your choice: ";

        // Input validation loop - ensures user enters a number
        while (!(cin >> choice)) {
            cin.clear();  // Clear error flag on cin
            // Discard invalid input up to newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }

        // Process user's choice using switch statement
        switch (choice) {
            case 1:  // Start quiz
                startQuiz(list);
                list.saveToFile("../data/studentInfo.csv");
                break;
            
            case 2:  // View high scores
                // IMPORTANT: Reload data from file before displaying
                list.loadFromFile("../data/studentInfo.csv");
                viewHighScore(list);
                break;
            
            case 3:  // Show instructions
                cout << "You have selected the option 3: Instructions";
                cout << "\n\n";
                break;
            
            case 4:  // Show credits
                cout << "You have selected the option 4: Credits";
                
                cout << "\n\n";
                break;

            case 5:  // Show credits
                cout << "You have selected the option 5: View My Profile";
                viewMyProfile(list);
                cout << "\n\n";
                break;
            case 6:  // Show credits
                cout << "You have selected the option 6: Delete My Profile";
                deleteMyProfile(list);
                cout << "\n\n";
                break;

                
            case 0:  // Exit program
                cout << "You have selected to exit the program. Goodbye!" << "\n\n";
                break;
                
            default:  // Invalid choice
                cout << "\n[WARNING]: Invalid Input!\n";
                break;
        }
        
        // Pause before returning to menu (except when exiting)
        if (choice != 0) {
            cout << "\nPress Enter to return to menu...";
            cin.ignore();   // Clear newline from previous input
            cin.get();      // Wait for Enter key
        }
    
    } while (choice != 0);  // Continue loop until user chooses 0 (Exit)

    cout << "Exiting the program...\n" << endl;
    return 0;  // Successful program termination
}

// Function to start the quiz process
void startQuiz(StudentList& list) 
{

    clearScreen();
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    // Create a temporary student object with default values
    Student newStudent("", "", "", 0, 0, 0, 0, 0);

    // Get student information
    cout << "Please enter your First Name: ";
    getline(cin, newStudent.firstName);  // Read entire line for first name

    cout << "Please enter your Last Name: ";
    getline(cin, newStudent.lastName);   // Read entire line for last name

    // Initialize credits (quiz functionality not fully implemented)
    cout << "You have been given 100 credits to take the quiz. Good Luck!";
    newStudent.credits = 100;

    
    // Add student to the list with current data
    // Note: score, attempts, rank, and date are currently 0
    list.addStudent(newStudent.firstName, newStudent.lastName, 
                   newStudent.score, newStudent.attempts, newStudent.rank, 
                   newStudent.date, newStudent.credits);
    
    // Save updated list to file
    
    return;
}

// Function to view high scores
void viewHighScore(StudentList& list) 
{
    clearScreen();
    
    // Note: Data reloading happens in main() before calling this function
    list.printList();  // Display all student records
    return;
}

void viewMyProfile(StudentList& list) 
{

    clearScreen();


    string userInput;
    cin.ignore();

    cout << "\n\nPlease enter the ID number: ";
    getline(cin, userInput);


    userInput = trim(userInput);
    list.printCurrentStudent(userInput);

    return;

}


void deleteMyProfile(StudentList& list)
{

    StudentList archiveList;


    clearScreen();


    cin.ignore();
    string userInput;
    
    cout << "\n\nPlease enter your Full Name or Student ID: ";
    getline(cin, userInput);

    userInput = trim(userInput);


    list.deleteProfile(userInput, archiveList);


    cout << "\n\nYour profile has been successfully archived!\n\n";


    return;


}