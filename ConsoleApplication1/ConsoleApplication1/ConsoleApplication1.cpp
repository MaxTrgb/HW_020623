/*Create an array of structures with associations containing information about:
student's last name, course, specialty (to represent the specialty, use lists (Enum), and to represent the course - integers) and grades in physics,
mathematicians:
If the specialty is "Computer Science", then the third grade is for programming;
If the specialty is "Informatics", then the third assessment is from numerical methods;
for all other specialties: "Mathematics and Economics", "Physics and Informatics",
"On-the-job training" - the third assessment - in pedagogy.
Functions that must be implemented:
For each student, display: last name and average score.
Calculate the number of students who study "excellently",
Calculate the percentage of students who study without threes ("excellent" and "good").
• Display the names of students who received grades "5" or "4" in physics.
Calculate the average score for each subject.
Calculate the number of "excellent" marks for each subject.*/

#include <iostream>
#include <string>
using namespace std;

// Enum representing different specialties
enum Specialty {

    ComputerScience,
    Informatics,
    MathematicsAndEconomics,
    PhysicsAndInformatics,
    OnTheJobTraining
};

// Structure representing a student
struct Student {

    string lastName;
    int course;
    Specialty specialty;
    int physicsGrade;
    int mathematicsGrade;
    int thirdGrade; // New grade field
};

double calculateAverageGrade(const Student students[], int size, int subject);
int countExcellentMarks(const Student students[], int size, int subject);
void displayStudentsWith45GradesInPhysics(const Student students[], int size);
double calculatePercentageWithoutThrees(const Student students[], int size);
int countExcellentStudents(const Student students[], int size);
void displayStudentInfo(const Student& student);

int main() {
    const int numStudents = 3;
    Student students[numStudents];

    // Assign student information
    students[0] = { "Homer Simpson", 1, ComputerScience, 5, 4, 5 }; // Third grade for Computer Science is programming
    students[1] = { "Petter Griffin", 2, Informatics, 3, 4, 4 }; // Third grade for Informatics is numerical methods
    students[2] = { "Stan Smith", 3, MathematicsAndEconomics, 4, 5, 5 }; // Third grade for Mathematics and Economics is pedagogy

    // Display student information
    for (int i = 0; i < numStudents; i++) {

        cout << "Student " << (i + 1) << ":" << endl;
        displayStudentInfo(students[i]);
        cout << endl;
    }

    // Calculate number of excellent students
    int excellentStudents = countExcellentStudents(students, numStudents);
    cout << "Number of Excellent Students: " << excellentStudents << endl;

    // Calculate percentage of students without threes
    double percentageWithoutThrees = calculatePercentageWithoutThrees(students, numStudents);
    cout << "Percentage of Students without Threes: " << percentageWithoutThrees << "%" << endl;

    // Display students with grades 4 or 5 in physics
    cout << "Students with Grades 4 or 5 in Physics:" << endl;
    displayStudentsWith45GradesInPhysics(students, numStudents);
    cout << endl;

    // Calculate average grade for each subject
    double averagePhysicsGrade = calculateAverageGrade(students, numStudents, 1);
    double averageMathematicsGrade = calculateAverageGrade(students, numStudents, 2);
    cout << "Average Grade in Physics: " << averagePhysicsGrade << endl;
    cout << "Average Grade in Mathematics: " << averageMathematicsGrade << endl;

    // Calculate number of excellent marks for each subject
    int excellentPhysicsMarks = countExcellentMarks(students, numStudents, 1);
    int excellentMathematicsMarks = countExcellentMarks(students, numStudents, 2);
    cout << "Number of Excellent Marks in Physics: " << excellentPhysicsMarks << endl;
    cout << "Number of Excellent Marks in Mathematics: " << excellentMathematicsMarks << endl;
}

// Function to display student information
void displayStudentInfo(const Student& student) {

    cout << "Name: " << student.lastName << endl;
    double averageGrade = (student.physicsGrade + student.mathematicsGrade + student.thirdGrade) / 3.0;
    cout << "Average Grade: " << averageGrade << endl;
}

// Function to count the number of excellent students
int countExcellentStudents(const Student students[], int size) {

    int count = 0;
    for (int i = 0; i < size; i++) {

        double averageGrade = (students[i].physicsGrade + students[i].mathematicsGrade + students[i].thirdGrade) / 3.0;
        if (averageGrade >= 4.5) {

            count++;
        }
    }
    return count;
}

// Function to calculate the percentage of students without threes
double calculatePercentageWithoutThrees(const Student students[], int size) {

    int count = 0;
    for (int i = 0; i < size; i++) {

        if (students[i].physicsGrade != 3 && students[i].mathematicsGrade != 3 && students[i].thirdGrade != 3) {

            count++;
        }
    }
    return (count * 100.0) / size;
}

// Function to display students with grades 4 or 5 in physics
void displayStudentsWith45GradesInPhysics(const Student students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].physicsGrade == 4 || students[i].physicsGrade == 5) {
            cout << "Name: " << students[i].lastName << endl;
        }
    }
}

// Function to calculate the average grade for a specific subject
double calculateAverageGrade(const Student students[], int size, int subject) {

    double sum = 0;
    for (int i = 0; i < size; i++) {

        if (subject == 1) {

            sum += students[i].physicsGrade;
        }
        else if (subject == 2) {

            sum += students[i].mathematicsGrade;
        }
        else if (subject == 3) {

            sum += students[i].thirdGrade;
        }
    }
    return sum / size;
}

// Function to count the number of excellent marks for a specific subject
int countExcellentMarks(const Student students[], int size, int subject) {
    int count = 0;
    for (int i = 0; i < size; i++) {

        if ((subject == 1 && (students[i].physicsGrade == 5 || students[i].physicsGrade == 4)) ||
            (subject == 2 && (students[i].mathematicsGrade == 5 || students[i].mathematicsGrade == 4)) ||
            (subject == 3 && (students[i].thirdGrade == 5 || students[i].thirdGrade == 4))) {

            count++;
        }
    }
    return count;
}
