#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Student information
struct Student {
    string firstName;
    string lastName;
    int studentID;
    float programmingGrades[10];
    float testGrades[3];
    float finalExam;
    float finalGrade;
    char letterGrade;
};

// Function to calculate final grade
float calculateFinalGrade(Student &student) {
    // Calculate programming assignments average (30%)
    float progTotal = 0;
    for(int i = 0; i < 10; i++) {
        progTotal += student.programmingGrades[i];
    }
    float progAverage = (progTotal / 10) * 0.30;
    
    // Calculate tests average (45% - 15% each)
    float testTotal = 0;
    for(int i = 0; i < 3; i++) {
        testTotal += student.testGrades[i] * 0.15;
    }
    
    // Calculate final exam (25%)
    float examGrade = student.finalExam * 0.25;
    
    // Return total grade
    return progAverage + testTotal + examGrade;
}

// Function to calculate letter grade
char getLetterGrade(float finalGrade) {
    if(finalGrade >= 90) return 'A';
    else if(finalGrade >= 80) return 'B';
    else if(finalGrade >= 70) return 'C';
    else if(finalGrade >= 60) return 'D';
    else return 'F';
}

int main() {
    Student student;
    ofstream outFile("GradeBook.txt");
    string input;
    
    if(!outFile) {
        cout << "\n================================================" << endl;
        cout << "❌ Error: Unable to create GradeBook.txt!" << endl;
        cout << "   Please contact your instructor for assistance." << endl;
        cout << "================================================" << endl;
        return 1;
    }
    
    cout << "\n================================================" << endl;
    cout << "📚 Welcome to Student Grade Management System" << endl;
    cout << "================================================" << endl;
    
    char addMore = 'y';
    
    while(tolower(addMore) == 'y') {
        // Get student information
        cout << "\nEnter student's first name: ";
        getline(cin, student.firstName);
        
        cout << "Enter student's last name: ";
        getline(cin, student.lastName);
        
        cout << "Enter 6-digit student ID: ";
        getline(cin, input);
        student.studentID = stoi(input);
        
        // Get programming assignment grades
        cout << "\nEnter 10 programming assignment grades:\n";
        for(int i = 0; i < 10; i++) {
            cout << "Assignment " << i + 1 << ": ";
            getline(cin, input);
            student.programmingGrades[i] = stof(input);
        }
        
        // Get test grades
        cout << "\nEnter 3 test grades:\n";
        for(int i = 0; i < 3; i++) {
            cout << "Test " << i + 1 << ": ";
            getline(cin, input);
            student.testGrades[i] = stof(input);
        }
        
        // Get final exam grade
        cout << "\nEnter final exam grade: ";
        getline(cin, input);
        student.finalExam = stof(input);
        
        // Calculate final grade and letter grade
        student.finalGrade = calculateFinalGrade(student);
        student.letterGrade = getLetterGrade(student.finalGrade);
        
        // Write to file
        outFile << student.firstName << " " << student.lastName << endl;
        outFile << "ID: " << student.studentID << endl;
        outFile << "Final Grade: " << student.finalGrade << endl;
        outFile << "Letter Grade: " << student.letterGrade << endl;
        outFile << "------------------------" << endl;
        
        // Display results
        cout << "\nResults for " << student.firstName << " " << student.lastName << ":" << endl;
        cout << "Final Grade: " << student.finalGrade << endl;
        cout << "Letter Grade: " << student.letterGrade << endl;
        
        cout << "\nAdd another student? (y/n): ";
        getline(cin, input);
        addMore = input[0];
    }
    
    outFile.close();
    cout << "\n================================================" << endl;
    cout << "✨ Great news! All student records have been successfully" << endl;
    cout << "   saved to GradeBook.txt." << endl;
    cout << "\n🎓 Thank you for using the Student Grade Management System!" << endl;
    cout << "   Have a great day! 📚" << endl;
    cout << "================================================" << endl;
    
    return 0;
}