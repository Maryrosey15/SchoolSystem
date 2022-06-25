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
void input();
vector <Student> readFromFile();
void deleteFromFile(string search);

//Global variables
char answer = 'y';
string searchInfo;
vector <Student> student;


int main()
{
    system("cls");
    cout << "\n\t\t\t\tSchool System Homepage";
    line();
    m:
    cout << "\n1 Student Record | 2 Add Student | 3 Delete Record | 4 Quit";
    cout << "\n\nType your choice here: ";
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 1:
            readFromFile();
            break;
        case 2:
            input();
            break;
        case 3:
            deleteFromFile(searchInfo);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\n\nInvalid choice...";
            goto m;
            break;
    }
    cout << "\n\n\n";
    return 0;
}

//================== Functions Definition =====================
void input() {
    Student s;
    cout << "\n\t\t\t\tAdd Student Information";
    line();
    do {
    cout << "\n\nEnter student name: ";
    cin >> s.name;
    cout << "Enter student age: ";
    cin >> s.age;
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
        myFile << student[i].name << "," << student[i].age << "," << student[i].grade << endl;
    }
    myFile.close();
    cout << "\n...Student Information added\n\n";
    
    main();
}

vector <Student> readFromFile() {
    ifstream myFile("student_file.csv");
    cout << "\n\n\t\t\t\tStudent Details From File";
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
    
    main();
    return (temp);
}

void deleteFromFile(string search) {
    cout << "\n\t\t\t\tDeleting student information";
    line();
    ifstream file_in("student_file.csv");
    ofstream file_out("temp.csv", ios::app);
    
    do {
        cout << "\n\nEnter student name to delete information: ";
        cin >> search;
        
        vector <Student> lines;
        string line;
        
        while (getline(file_in, line)) {
            file_out << line << endl;
        }
    file_out.close();
    file_in.close();
    remove("student_file.csv");
    rename("temp.csv", "student_file.csv");
    cout << "\n...Deleted the file successfully";
    readFromFile();
    
    cout << "\n\nDo you want to delete more student? ";
    cout << "\n\nEnter y = yes and n = no: ";
    cin >> answer;
    
    } while(_tolower(answer) == 'y');
    
    main();
}

void line()
{
    cout<<"\n-------------------------------------------------------------------\n";
}
