//
//  main.cpp
//  schoolSystem
//
//  Created by Mary Rose V. Garcia on 23/06/22.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//Structures
struct Student {
    string name;
    string age;
    string grade;
    
    Student(string n = "", string a = "", string g = "") {
        name = n;
        age = a;
        grade = g;
    }
};

//================== Functions Declaration =====================
void line();
vector <Student> input(vector <Student>& student);
vector <Student> readFromFile();

//Gloabl variables
char answer = 'y';

int main()
{
    vector <Student> student;
    input(student);
    readFromFile();
    
    cout << "\n\n\n";
    return 0;
}

//================== Functions Definition =====================
vector <Student> input(vector <Student>& student) {
    Student s;
    cout << "\n\t\t\t\tAdd Student Information";
    line();
    do {
    cout << "\n\nEnter student name: ";
    getline(cin, s.name);
    cin.ignore();
    cout << "Enter student age: ";
    getline(cin, s.age);
    cin.ignore();
    cout << "Enter student grade: ";
    cin >> s.grade;
        
        student.push_back(s);
    
    cout << "\n\n\t\t\t\tStudent details";
    line();
    cout << "\nStudent name: " << s.name;
    cout << "\nStudent age: " << s.age;
    cout << "\nStudent grade: " << s.grade;
        
    cout << "\n\nDo you want to add more student? (Type Y = yes and N = no): ";
    cin >> answer;
    } while(tolower(answer) == 'y');
    ofstream myFile("student_file.csv", ios::app);
    for (int i = 0; i < student.size(); i++) {
        myFile << s.name << "," << s.age << "," << s.grade << endl;
    }
    myFile.close();
    
    return (student);
}

vector <Student> readFromFile() {
    ifstream myFile("student_file.csv");
    cout << "\n\t\t\t\tStudent Details From File";
    line();
    
    vector <Student> temp;
    Student s;
    string line;
    
    while (getline(myFile, line)) {
        cout << line << endl;
        istringstream linestream(line);
        string item1, item2, item3;
        s.name = item1;
        s.age = item2;
        s.grade = item3;
        
        getline(linestream, item1, ',');
        
        temp.push_back(s);
    }
    myFile.close();
    return (temp);
}

void line()
{
    cout<<"\n===============================================\n";
}
