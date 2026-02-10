#ifndef STUDENT_H  // Prevent multiple inclusion of this file
#define STUDENT_H

#include <string>


using namespace std;


struct Student {
    string id;
    string firstName;
    string lastName; 
    string dateCreated;
    string dateDeleted;
    string status;
    int score;
    int attempts;
    int rank;
    int date;
    int credits;
    


    // Constructor declaration ONLY

    Student(string id, string fn, string ln, int scr, int attmpt, int r, int d, int crdts);

    Student(string id, string dateCreated, string dateDeleted, string status);

    void displayInfo() const;
    string getFullName() const;

};

string getTodayDate();

struct Date {
    int month;
    int day;
    int year;
};

struct Time {
    int hours;
    int minutes;
    int seconds;
};


#endif 