#include <iostream>    // For printing output
#include "students.h"  // Include your header file
#include "person.h"

int main() {
    // Create a Student object
    oop_practice::Student s("Alice", 20, 8.0);
    std::cout << s.getAge() << std::endl;
    s.printInfo();

    oop_practice::Student::Course c("Math 101", 2004);

    s.enroll(c);

    s.printCourses();

    std::cout<<oop_practice::compareGrades(s, s);

    // Person related logic

    oop_practice2::Person p1{"Alice", 30, {"reading", "hiking"}};
    oop_practice2::Person p2 = p1; // Compiler-generated copy constructor
    p2.name = "Bob";
    p2.hobbies.push_back("swimming");

    return 0;
}
