#include <iostream>
#include <iomanip>
using namespace std;

struct Course
{
    string courseName;
    char grade;
    int credits;
    double gradePoint;
};

// Convert grade to grade point
double getGradePoint(char grade)
{
    switch (grade)
    {
        case 'A':
        case 'a':
            return 10;

        case 'B':
        case 'b':
            return 8;

        case 'C':
        case 'c':
            return 7;

        case 'D':
        case 'd':
            return 6;

        case 'E':
        case 'e':
            return 5;

        case 'F':
        case 'f':
            return 0;

        default:
            return -1;
    }
}

int main()
{
    int n;

    cout << "==============================" << endl;
    cout << "       CGPA CALCULATOR" << endl;
    cout << "==============================" << endl;

    cout << "Enter number of courses: ";
    cin >> n;

    Course courses[20];

    double totalCredits = 0;
    double totalGradePoints = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> courses[i].courseName;

        cout << "Enter grade (A/B/C/D/E/F): ";
        cin >> courses[i].grade;

        cout << "Enter credit hours: ";
        cin >> courses[i].credits;

        courses[i].gradePoint = getGradePoint(courses[i].grade);

        if (courses[i].gradePoint == -1)
        {
            cout << "Invalid grade!" << endl;
            return 0;
        }

        totalCredits += courses[i].credits;

        totalGradePoints +=
            courses[i].gradePoint * courses[i].credits;
    }

    double gpa = totalGradePoints / totalCredits;

    cout << "\n==============================" << endl;
    cout << "       COURSE DETAILS" << endl;
    cout << "==============================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Course: " << courses[i].courseName
             << " | Grade: " << courses[i].grade
             << " | Credits: " << courses[i].credits
             << " | Grade Point: " << courses[i].gradePoint
             << endl;
    }

    cout << fixed << setprecision(2);

    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester GPA      : " << gpa << endl;

    cout << "\n==============================" << endl;
    cout << "          FINAL CGPA" << endl;
    cout << "==============================" << endl;

    cout << "Your CGPA is: " << gpa << endl;

    return 0;
}