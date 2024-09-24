#include <iostream>    // For printing output
#include "students.h"  // Include your header file

int main() {
    // Create a Student object
    oop_practice::Student s("Alice", 20, 8.0);
    std::cout << s.getAge() << std::endl;
    s.printInfo();

    return 0;
}
