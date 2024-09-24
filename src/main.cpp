#include <iostream>    // For printing output
#include "students.h"  // Include your header file

int main() {
    // Create a Student object
    oop_practice::Student s("Alice", 20, 8.0);
    std::cout << s.getAge() << std::endl;
    s.printInfo();

    oop_practice::Student::Course c("Math 101", 2004);

    s.enroll(c);

    s.printCourses();

    std::cout<<oop_practice::compareGrades(s, s);

    return 0;
}
