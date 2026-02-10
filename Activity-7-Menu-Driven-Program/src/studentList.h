#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "student.h"
#include <vector>
#include <string>

class StudentList {



private :


    vector<Student> students;



    int nextID;
    string tempStudentID;

    int extractIDNumber(const string& fullID);

    void updateNextID();


public :

    StudentList();

    void loadFromFile(const string& filename);
    
    void addStudent(string fn, string ln, int scr, int attmpts, int r, int d, int crdts);


    void updateBackup(const string& filename);
    void saveToArchive(const Student& s);
    void saveToBackUP(string date);
    void saveToFile(const string& filename);
    void printList();
    
    void printCurrentStudent(string userInput);
    void deleteProfile(string userInput, StudentList& archiveList);
    void addDeletedStudent(string studentID, string date);
    
    



};


#endif