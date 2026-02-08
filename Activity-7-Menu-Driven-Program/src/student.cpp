#include "student.h"
#include <iostream>
#include <vector>
using namespace std;



Student::Student(string id, string fn, string ln, int scr, int attmpt, int r, int d, int crdts) : id(id), firstName(fn), lastName(ln), score(scr), attempts(attmpt), rank(r), date(d), credits(crdts) {} 


void Student::displayInfo() const {
    cout << "Name: " <<  firstName << " " << lastName << endl;
    cout << "ID: " << id << " | Score: " << score << endl;
}

string Student::getFullName() const {
    return firstName + " " + lastName;
}