#include <gtest/gtest.h>
#include <list>
#include <string>
#include "students.h"

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

    TEST(OOP_HMK, TestEnroll) {

        oop_practice::Student student1("Ricardo", 20, 8.5);

        oop_practice:Student::Course c1;

        std::string name = student1.
        ASSERT_EQ(name, "Ricardo");

        int age = student1.getAge();
        ASSERT_EQ(age, 20);
        ASSERT_EQ(student1.getAgeAccessed(), true);

        double grade = student1.getGrade();
        ASSERT_EQ(grade, 8.5);
    }
}