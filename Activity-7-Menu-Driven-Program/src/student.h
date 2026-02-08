#ifndef STUDENT_H  // Prevent multiple inclusion of this file
#define STUDENT_H

#include <string>


using namespace std;


struct Student {
    string id;
    string firstName;
    string lastName; 
    int score;
    int attempts;
    int rank;
    int date;
    int credits;



    // Constructor declaration ONLY

    Student(string id, string fn, string ln, int scr, int attmpt, int r, int d, int crdts);

    void displayInfo() const;
    string getFullName() const;

};

#endif 