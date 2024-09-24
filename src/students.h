#pragma once

#include <string>
#include <random>
#include <vector>

namespace oop_practice {

    class Student {
        std::string name;
        int age;
        double grade;
        static int totalStudents;
        mutable bool ageAccessed;

    public:
        Student();
        Student(std::string in_name, int in_age, double in_grade);

        int getAge() const;
        double getGrade() const;
        std::string getName() const;
        bool getAgeAccessed() const;

        void setAge(int newAge);      // Setters should return void
        void setGrade(double newGrade);
        void setName(const std::string& newName);

        const int printInfo();

        int getTotalStudents() const;

        friend bool compareGrade(const Student& a, const Student& b);


        class Course {
        public:
            std::string courseName;
            int year;
           
        };


    // defined after public Course definition

     int enroll(Course course);

    std::vector<Student::Course> courses;



    private:
        const void generateStudentInfo();
    };

}

namespace detail {
    class RandomGenerator {
        static std::random_device rd;
        static std::mt19937 rng;

    public:
        template <typename T>
        static T getRandomNumber(T min, T max) {
            if constexpr (std::is_integral_v<T>) {
                std::uniform_int_distribution<T> dist(min, max);
                return dist(rng);
            } else if constexpr (std::is_floating_point_v<T>) {
                std::uniform_real_distribution<T> dist(min, max);
                return dist(rng);
            }
        }

        static std::string generateRandomName();
    };
}