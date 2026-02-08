#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "student.h"
#include <vector>
#include <string>

class StudentList {



private :


    vector<Student> students;


    int nextID;

    int extractIDNumber(const string& fullID);

    void updateNextID();


public :

    StudentList();
    void saveToArchive(const Student& s);
    void addStudent(string fn, string ln, int scr, int attmpts, int r, int d, int crdts);

    void addArchive(string id, string fn, string ln, int scr, int attmpts, int r, int d, int crdts);

    void saveToFile(const string& filename);
    void printList();
    void loadFromFile(const string& filename);
    void printCurrentStudent(string userInput);
    void deleteProfile(string userInput, StudentList& archiveList);
    



};


#endif