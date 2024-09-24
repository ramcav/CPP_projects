#include <gtest/gtest.h>
#include <list>
#include <string>
#include "students.h"
#include <vector>

namespace oop_tests {

    TEST(OOP_HMK, TestGetters) {

        oop_practice::Student student1("Ricardo", 20, 8.5);

        std::string name = student1.getName();
        ASSERT_EQ(name, "Ricardo");

        int age = student1.getAge();
        ASSERT_EQ(age, 20);
        ASSERT_EQ(student1.getAgeAccessed(), true);

        double grade = student1.getGrade();
        ASSERT_EQ(grade, 8.5);
    }

    TEST(OOP_HMK, TestSetters) {
        oop_practice::Student student1("Ricardo", 20, 8.5);

        student1.setName("John");

        std::string name = student1.getName();
        ASSERT_EQ(name, "John");

        student1.setAge(100);

        int age = student1.getAge();
        ASSERT_EQ(age, 100);

        student1.setGrade(10);

        int grade = student1.getGrade();
        ASSERT_EQ(grade, 10);
    }

    TEST(OOP_HMK, TestEnroll) {

        oop_practice::Student student1("Ricardo", 20, 8.5);

        oop_practice::Student::Course c1("Math 101", 2019);

        student1.enroll(c1);

        std::vector<oop_practice::Student::Course> courses = student1.getCourses();

        std::vector<oop_practice::Student::Course> expected = {c1};

        ASSERT_EQ(courses, expected);

    }

    TEST(OOP_HMK, TestCompare) {
        oop_practice::Student student1("Ricardo", 20, 8.5);
        oop_practice::Student student2("Juan", 21, 9.0);

        bool result = oop_practice::compareGrades(student1, student2);
        ASSERT_EQ(result, false);

        result = oop_practice::compareGrades(student2, student1);
        ASSERT_EQ(result, true);
    }

    TEST(OOP_HMK, TestTotal) {
        oop_practice::Student student1("Ricardo", 20, 8.5);
        oop_practice::Student student2("Juan", 21, 9.0);
        oop_practice::Student student3("Andrea", 23, 7);
        oop_practice::Student student4("Roberto", 18, 3.0);

        int total1 = student1.getTotalStudents();
        int total2 = student2.getTotalStudents();

        ASSERT_EQ(total1, total2);
        ASSERT_EQ(total1, 4);
    }
}