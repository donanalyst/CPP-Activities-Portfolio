// Include necessary header files for various functionalities
#include <iostream>      // For basic input/output operations
#include <vector>        // For using vector container
#include <limits>        // For numeric_limits (used in input validation)
#include <list>          // For list container (though not used in current code)
#include <fstream>       // For file handling (reading and writing to file)
#include <string>        // For string class
#include <sstream>       // For string streams (parsing strings)
#include <iterator>      // For iterators (though not directly used)

// Using standard namespace to avoid prepending std:: to every standard function/object
using namespace std;

// Structure for student
// Contains all required student information
struct student
{
    string firstName;    // Student's first name
    string lastName;     // Student's last name
    string id;           // Student ID (format: "2026XX")
    int score;           // Quiz score
    int attempts;        // Number of attempts taken
    int rank;            // Ranking position
    int date;            // Date information (could be quiz date)
    int credits;         // Available credits for quiz attempts

    // Constructor for initializing student structure
    student(string fn, string ln, string id, int scr, int attmpt, int r, int d, int crdts) 
        : firstName(fn), lastName(ln), id(id), score(scr), attempts(attmpt), rank(r), date(d), credits(crdts) {}
};

// Class to manage list of students
class studentList {
private: 
    vector<student> students;  // Vector container to store student objects
    int nextID = 1;            // Counter for generating next student ID

    // Function to extract numeric part from student ID string
    int extractIDNumber(const string& fullID) {
        if (fullID.length() >= 6) {               // Check if ID has minimum required length
            string numStr = fullID.substr(4);     // Extract substring starting from position 4 (after "2026")
            try {
                return stoi(numStr);              // Convert string to integer
            } catch (...) {                        // Catch any conversion errors
                // Return 0 if conversion fails
            }
        }
        return 0;  // Return 0 if ID format is invalid
    }
    
    // Function to update nextID based on existing students in the list
    void updateNextID() {
        int maxID = 0;  // Variable to track highest ID number found
        // Loop through all students to find the highest ID number
        for (const auto& s : students) {
            int idNum = extractIDNumber(s.id);  // Extract numeric part of ID
            if (idNum > maxID) maxID = idNum;   // Update maxID if current is larger
        }
        nextID = maxID + 1;  // Set nextID to one more than the highest found
    }

public: 
    // Function to add a new student to the list
    void addStudent(string fn, string ln, int scr, int attmpt, int r, int d, int crdts)
    {   
        // Convert nextID to string and pad with leading zero if less than 10
        string idNum = to_string(nextID);
        if (nextID < 10) idNum = "0" + idNum;
        
        // Create full student ID by combining "2026" with padded number
        string studentID = "2026" + idNum;
        
        // Add new student to vector using emplace_back (more efficient than push_back)
        students.emplace_back(fn, ln, studentID, scr, attmpt, r, d, crdts);

        nextID++;  // Increment ID counter for next student
    }
    
    // Function to save all student data to a CSV file
    void saveToFile()  {
        // Open file for writing (creates new or overwrites existing)
        ofstream file("studentInfo.csv");
        if (!file.is_open()) {  // Check if file opened successfully
            cout << "Failed to open file" << endl;
            return;
        };

        // Write CSV header row
        file << "firstName,lastName,id,score,attempts,rank,date,credits\n";
        
        // Loop through all students and write their data
        for (auto& student : students) {
            file << student.firstName << ",";
            file << student.lastName << ",";
            file << student.id << ",";
            file << student.score << ",";
            file << student.attempts << ",";
            file << student.rank << ",";
            file << student.date << ",";
            file << student.credits << "\n";
        }   
        
        file.close();  // Close the file
        cout << "\n\nData was saved." << endl;  // Confirm save operation
    }

    // Function to display all students' information to console
    void printList() const {
        // Loop through all students and print their details
        for (auto& student : students) {
            cout << "Name: " << student.firstName << " " << student.lastName << endl;
            cout << "ID: " << student.id << endl;
            cout << "Score: " << student.score << endl;
            cout << "Attempts: " << student.attempts << endl;
            cout << "Rank: " << student.rank << endl;
            cout << "Date: " << student.date << endl;
            cout << "Credits: " << student.credits << endl;
            cout << "-----------------" << endl;  // Separator between students
        }
    }

    // Function to load student data from a CSV file
    void loadFromFile(const string& filename) {
        students.clear();  // CRITICAL FIX: Clear existing data before loading new data
        
        // Open file for reading
        ifstream file("studentInfo.csv");
        if (!file.is_open()) {  // Check if file opened successfully
            cout << "Failed to open file" << endl;
            return;
        }

        cout << "Loading data from file..." << endl;
        string line;  // Variable to hold each line read from file
        
        getline(file, line);  // Read and discard the header line
        
        // Read file line by line until end of file
        while (getline(file, line)) {
            istringstream iss(line);  // Create string stream from line for parsing
            
            // Variables to hold each field from CSV
            string firstName, lastName, id, scoreStr, attemptsStr, rankStr, dateStr, creditsStr;
            
            // Parse CSV fields using comma as delimiter
            getline(iss, firstName, ',');
            getline(iss, lastName, ',');
            getline(iss, id, ',');
            getline(iss, scoreStr, ',');
            getline(iss, attemptsStr, ',');
            getline(iss, rankStr, ',');
            getline(iss, dateStr, ',');
            getline(iss, creditsStr, ',');

            // Convert string fields to integers
            int score = stoi(scoreStr);
            int attempts = stoi(attemptsStr);
            int rank = stoi(rankStr);
            int date = stoi(dateStr);
            int credits = stoi(creditsStr);

            // Add new student to vector with parsed data
            students.emplace_back(firstName, lastName, id, score, attempts, rank, date, credits);
        }

        file.close();  // Close the file
        cout << "Data was loaded." << endl;  // Confirm load operation

        updateNextID();  // Update nextID counter based on loaded data
    }
};

// Function prototypes (declared before main, defined after)
void viewHighScore(studentList& list);  // Display high scores
void startQuiz(studentList& list);      // Start quiz process

// Main function - program entry point
int main() {
    // Create decorative borders for UI
    string border(36, '=');  // String of 36 '=' characters
    string space(6, ' ');    // String of 6 space characters

    studentList list;  // Create studentList object to manage students

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
                break;
            
            case 2:  // View high scores
                // IMPORTANT: Reload data from file before displaying
                list.loadFromFile("studentInfo.csv");
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
void startQuiz(studentList& list) {
    cin.ignore();  // Clear newline from previous input

    // Create a temporary student object with default values
    student newStudent("", "", "", 0, 0, 0, 0, 0);

    // Get student information
    cout << "Please enter your first name: ";
    getline(cin, newStudent.firstName);  // Read entire line for first name

    cout << "Please enter your last name: ";
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
    list.saveToFile();
    return;
}

// Function to view high scores
void viewHighScore(studentList& list) {
    // Note: Data reloading happens in main() before calling this function
    list.printList();  // Display all student records
    return;
}