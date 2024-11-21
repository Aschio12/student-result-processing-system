#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a Student
struct Student {
    string name;
    int rollNumber;
    string course;

    // Constructor to initialize student details
    Student(string name, int rollNumber, string course)
        : name(name), rollNumber(rollNumber), course(course) {}
};

// Class to handle student registration system
class StudentRegistrationSystem {
private:
    vector<Student> students;  // List of registered students

public:
    // Function to add a student to the system
    void addStudent() {
        string name, course;
        int rollNumber;

        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore();  // To ignore the newline character left by cin
        cout << "Enter course: ";
        getline(cin, course);

        // Create a new student object and add it to the list
        Student newStudent(name, rollNumber, course);
        students.push_back(newStudent);

        cout << "Student registered successfully!" << endl;
    }

    // Function to display all registered students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students registered yet." << endl;
        } else {
            cout << "\nList of Registered Students:" << endl;
            for (const auto& student : students) {
                cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber
                     << ", Course: " << student.course << endl;
            }
        }
    }

    // Function to search for a student by roll number
    void searchStudentByRollNumber() {
        int rollNumber;
        cout << "Enter roll number to search: ";
        cin >> rollNumber;

        bool found = false;
        for (const auto& student : students) {
            if (student.rollNumber == rollNumber) {
                cout << "Student found!" << endl;
                cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber
                     << ", Course: " << student.course << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << rollNumber << " not found!" << endl;
        }
    }

    // Function to delete a student by roll number
    void deleteStudent() {
        int rollNumber;
        cout << "Enter roll number to delete: ";
        cin >> rollNumber;

        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->rollNumber == rollNumber) {
                students.erase(it);
                cout << "Student with roll number " << rollNumber << " deleted successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << rollNumber << " not found!" << endl;
        }
    }
};

// Main function
int main() {
    StudentRegistrationSystem system;
    int choice;

    do {
        cout << "\nStudent Registration System\n";
        cout << "1. Register a Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Delete Student by Roll Number\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left by cin

        switch (choice) {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.displayStudents();
                break;
            case 3:
                system.searchStudentByRollNumber();
                break;
            case 4:
                system.deleteStudent();
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}

