#include "student.h"
#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;





Student::Student(string id, string fn, string ln, int scr, int attmpt, int r, int d, int crdts) : id(id), firstName(fn), lastName(ln), score(scr), attempts(attmpt), rank(r), date(d), credits(crdts) {} 

Student::Student(string id, string dateCreated, string dateDeleted, string status) : id(id), dateCreated(getTodayDate()), dateDeleted(getTodayDate()), status("Active") {}


void Student::displayInfo() const {
    cout << "Name: " <<  firstName << " " << lastName << endl;
    cout << "ID: " << id << " | Score: " << score << endl;
}

string Student::getFullName() const {
    return firstName + " " + lastName;
}

