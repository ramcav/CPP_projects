#include "students.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

namespace oop_practice {

    int Student::totalStudents = 0;

    // Constructors
    Student::Student(std::string in_name, int in_age, double in_grade) {
        ageAccessed = false;
        setAge(in_age);
        setGrade(in_grade);
        setName(in_name);

        this->totalStudents += 1;
    }

    Student::Student() {
        ageAccessed = false;
        generateStudentInfo();
        this->totalStudents += 1;
    }

    // Getters
    int Student::getAge() const {
        ageAccessed = true;
        return this->age;
    }

    double Student::getGrade() const {
        return this->grade;
    }

    std::string Student::getName() const {
        return this->name;
    }

    bool Student::getAgeAccessed() const {
        return this->ageAccessed;
    }

    int Student::getTotalStudents() const {
        return this->totalStudents;
    }

    bool compareGrade(const Student& a, const Student& b) {
        return a.getGrade() > b.getGrade();
    };

    // Setters
    void Student::setAge(int newAge) {
        if (newAge >= 0 && newAge <= 120) {
            this->age = newAge;
        } else {
            throw std::invalid_argument("received age less than 0 or greater than 120");
        }
    }

    void Student::setGrade(double newGrade) {
        if (newGrade >= 0.0 && newGrade <= 10.0 ) {
            this->grade = newGrade;
        } else {
            throw std::invalid_argument("received grade less than 0.0 or greater than 10.0");
        }
    }

    void Student::setName(const std::string& newName) {
        if (newName.length() >= 0 && newName.length() <= 30) {
            this->name = newName;
        } else {
            throw std::invalid_argument("name has no characters or more than 30");
        }
    }

    // Private method to generate student info
   const void Student::generateStudentInfo() {
        setName(detail::RandomGenerator::generateRandomName());
        setAge(age = detail::RandomGenerator::getRandomNumber(18, 24));
        setGrade(grade = detail::RandomGenerator::getRandomNumber(0.0, 10.0));
    }

    // Print info
    const int Student::printInfo() {

        std::cout<<"PRINTING STUDENT SUMMARY"<<std::endl;
        std::cout<<"name: "<<getName()<<std::endl;
        std::cout<<"age: "<<getAge()<<std::endl;
        std::cout<<"grade: "<<getGrade()<<std::endl;
        std::cout<<std::endl;
        std::cout<<"TOTAL STUDENTS: "<<getTotalStudents()<<std::endl;
        
        if (getAgeAccessed()) {
            std::cout<<"AGE has been accessed"<<std::endl;
        }

        return 0;
    }

    int Student::enroll(Course course) {
        this->courses.push_back(course);
        return 0;
    }
}

namespace detail {
    // Static members: global seed and random devices for the namespace
    std::random_device RandomGenerator::rd;
    std::mt19937 RandomGenerator::rng(RandomGenerator::rd());

    // Choose a random name
    std::string RandomGenerator::generateRandomName() {
        std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank"};
        int index = RandomGenerator::getRandomNumber(0, static_cast<int>(names.size() - 1));
        return names[index];
    }
}