#include "studentList.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;


StudentList::StudentList() : nextID(1) {}

int StudentList::extractIDNumber(const string& fullID) 
{
    if (fullID.length() >= 6) 
    {

        string numStr = fullID.substr(4);

        try 
        {
            return stoi(numStr);

        } 
        
        catch (...) 
        {

        }
    }
    return 0;

}

void StudentList::saveToArchive(const Student& s)
{
    bool writeHeader = false;
    {
        ifstream check("../data/archiveInfo.csv");
        writeHeader = check.peek() == ifstream::traits_type::eof();
    }

    ofstream file("../data/archiveInfo.csv", ios::app);
    if (!file)
    {
        cerr << "Error opening archive file!\n";
        return;
    }

    // Write header ONLY ONCE
    if (writeHeader)
    {
        file << "ID,FirstName,LastName,Score,Attempts,Rank,Date,Credits,Status\n";
    }

    // Write student data
    file << s.id << ","
         << s.firstName << ","
         << s.lastName << ","
         << s.score << ","
         << s.attempts << ","
         << s.rank << ","
         << s.date << ","
         << s.credits << ","
         << "Deleted" << "\n";
}


void StudentList::updateNextID() 
{
    int maxID = 0;

    for (const auto& s : students) {
        int idNum = extractIDNumber(s.id);
        if (idNum > maxID) maxID = idNum;

    }
    nextID = maxID + 1;


}


void StudentList::addStudent(
    string fn,
    string ln,
    int scr,
    int attmpt,
    int r,
    int d,
    int crdts
)
{
    // Ensure proper name formatting
    fn = toTitleCase(trim(fn));
    ln = toTitleCase(trim(ln));

    // Generate ID
    ostringstream oss;
    oss << "2026" << setw(2) << setfill('0') << nextID;
    string studentID = oss.str();

    // Add student (MATCHES Student constructor order)
    students.emplace_back(studentID, fn, ln, scr, attmpt, r, d, crdts);

    nextID++;
}

void StudentList::saveToFile(const string& filename) 
{
    ofstream file(filename);
    if (!file.is_open()) 
    {
        cout << "\n\n[WARNING]: Failed to open file." << endl;
        return;
    };

    file << "id,firstName,lastName,score,attempts,rank,date,credits\n";

    for (auto& student : students) 
    {
        file << student.id << ",";
        file << toTitleCase(student.firstName) << ",";
        file << toTitleCase(student.lastName) << ",";
        file << student.score << ",";
        file << student.attempts << ",";
        file << student.rank << ",";
        file << student.date << ",";
        file << student.credits << "\n";
    }

    file.close();
    cout << "\n\nData was saved." << endl;
}




void StudentList::printList()
{
    if (students.empty()) {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n------------------------------------\n";

    for (const auto& student : students)
    {
        cout << "ID\t\t: " << student.id << endl;
        cout << "Name\t\t: " << student.firstName << " " << student.lastName << endl;
        cout << "Score\t\t: " << student.score << endl;
        cout << "Attempts\t: " << student.attempts << endl;
        cout << "Rank\t\t: " << student.rank << endl;
        cout << "Date\t\t: " << student.date << endl;
        cout << "Credits\t\t: " << student.credits << endl;
        cout << "------------------------------------\n";
    }
}


void StudentList::loadFromFile(const string& filename) 
{
    students.clear();

    cout << "\n\n";

    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "\n\n[WARNING]: Failed to open file!" << endl;
        nextID = 1;
        return;

    }
    cout << "Loading data from file from " << filename << "..." << endl;
    string line;


    int loadedCount = 0;
    int errorCount = 0;

    getline(file, line);

    while (getline(file, line)) 
    {
        if (line.empty()) continue;

        istringstream iss(line);

        string id, firstName, lastName, scoreStr, attemptsStr, rankStr, dateStr, creditsStr;

        // Parse all fields
        if (!getline(iss, id, ',') ||
            !getline(iss, firstName, ',') ||
            !getline(iss, lastName, ',') ||
            !getline(iss, scoreStr, ',') ||
            !getline(iss, attemptsStr, ',') ||
            !getline(iss, rankStr, ',') ||
            !getline(iss, dateStr, ',') ||
            !getline(iss, creditsStr, ',')) {
            
            cout << "Warning: Invalid CSV format in line: " << line << endl;
            errorCount++;
            continue;
        }

        if (id.length() != 6 || id.substr(0, 4) != "2026") 
        {
            cout << "Warning: Invalid ID format: " << id << endl;
            errorCount++;
            continue;
        }

        try {
            int score = stoi(scoreStr);
            int attempts = stoi(attemptsStr);
            int rank = stoi(rankStr);
            int date = stoi(dateStr);
            int credits = stoi(creditsStr);
            
            students.emplace_back(id, firstName, lastName,score, attempts, rank, date, credits);
            loadedCount++;
            

        } catch (const invalid_argument& e) {
            cout << "Warning: Invalid number in line: " << line << endl;
            errorCount++;
        } catch (const out_of_range& e) {
            cout << "Warning: Number too large in line: " << line << endl;
            errorCount++;
        }
    }

    file.close();
    
    updateNextID();

    cout << "\n\n" << "Data loaded successfully!" << endl;
    cout << "Loaded: " << loadedCount << " students" << endl;
    if (errorCount > 0) {
        cout << "Errors: " << errorCount << " lines skipped" << endl;
    }
    
        
}

void StudentList::printCurrentStudent(string userInput)
{
    bool found = false;

    for (const auto& student : students)
    {

        string fullName = student.firstName + " " + student.lastName;
        
        if (userInput == student.id || toTitleCase(userInput) == fullName)
        {
            cout << "\n\nStudent Information Found!\n\n";
            cout << "Name: " << student.firstName << " " << student.lastName << endl;
            cout << "ID: " << student.id << endl;
            cout << "Score: " << student.score << endl;
            cout << "Attempts: " << student.attempts << endl;
            cout << "Rank: " << student.rank << endl;
            cout << "Date: " << student.date << endl;
            cout << "Credits: " << student.credits << endl;
            cout << "-----------------------" << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\n[NOTE]: Student not found!\n";
    }
}

void StudentList::deleteProfile(string userInput, StudentList& archiveList)
{
    char confirm;
    bool found = false;

    for (auto it = students.begin(); it != students.end(); )
    {
        string fullName = trim(it->firstName + " " + it->lastName);

        if (it->id == userInput || fullName == toTitleCase(userInput))
        {
            cout << "\nStudent Information Verified!\n\n";
            cout << "Full Name: " << fullName << "\n";
            cout << "Student ID: " << it->id << "\n\n";

            cout << "Are you sure you want to delete your profile? [Y/N]: ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            found = true;

            if (confirm == 'Y' || confirm == 'y')
            {
                // ✅ SAVE FIRST BEFORE ERASE
                saveToArchive(*it);

                // ✅ REMOVE FROM ACTIVE LIST
                it = students.erase(it);

                // ✅ SAVE UPDATED ACTIVE LIST
                saveToFile("studentInfo.csv");

                cout << "\nDeletion successful.\n";
            }
            else
            {
                cout << "\nDeletion cancelled.\n";
            }
            break;
        }
        else
        {
            ++it;
        }
    }

    if (!found)
    {
        cout << "\n[NOTE]: Student not found!\n";
    }
}
