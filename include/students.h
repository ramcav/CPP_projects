#pragma once

#include <string>
#include <random>
#include <vector>

/**
 * @file students.h
 * @brief This file contains the declarations of the Student and Course classes, as well as
 * general classes like RandomGenerator, which are contained in the detail namespace.
 */

namespace oop_practice {

    
    /**
     * @class Student
     * @brief Represents a student with name, age, grade, and enrolled courses.
     * 
     * The Student class provides functionality to store and manipulate information about a student.
     * It includes methods to get and set the student's name, age, grade, and enrolled courses.
     * The class also keeps track of the total number of students created.
     * 
     * @note The Student class is part of a larger program and is intended to be used in conjunction with other classes.
     */

    class Student {
        std::string name;
        int age;
        double grade;
        static int totalStudents;
        mutable bool ageAccessed;

    public:


        /**
         * @class Course
         * @brief Represents a course.
         * 
         * This class represents a course with a name and a year. It provides functionality to compare two courses for equality.
         */
        class Course {
        public:
            Course(std::string in_courseName, int in_year);
            std::string courseName;
            int year;

            /**
             * @brief Compare two courses for equality.
             * 
             * @param other The other course to compare.
             * @return True if the courses are equal.
             */
            bool operator==(const Course& other) const;
        
        };
            

        /**
         * @brief Default constructor for the Student class.
         * 
         * @note uses the generateStudentInfo() method to generate random student info.
         */
        Student();

        /**
         * @brief Constructor for the Student class.
         * 
         * @param in_name The name of the student.
         * @param in_age The age of the student.
         * @param in_grade The grade of the student.
         */
        Student(std::string in_name, int in_age, double in_grade);

        /**
         * @brief Get the age of the student.
         * 
         * @return The age of the student.
         */
        int getAge() const;

        /**
         * @brief Get the grade of the student.
         * 
         * @return The grade of the student.
         */
        double getGrade() const;

        /**
         * @brief Get the name of the student.
         * 
         * @return The name of the student.
         */
        std::string getName() const;

        /**
         * @brief Get if the variable Age has been accessed for a given student.
         * 
         * @return The ageAccessed of the student.
         */
        bool getAgeAccessed() const;

        /**
         * @brief Get the courses of the student.
         * 
         * @return The courses of the student.
         */
        std::vector<Student::Course> getCourses() const;

        /**
         * @brief Set the age of the student.
         * 
         * @param newAge The new age of the student.
         */
        void setAge(int newAge);

        /**
         * @brief Set the grade of the student.
         * 
         * @param newGrade The new grade of the student.
         */
        void setGrade(double newGrade);

        /**
         * @brief Set the name of the student.
         * 
         * @param newName The new name of the student.
         */
        void setName(const std::string& newName);

        /**
         * @brief Print the student's information.
         * 
         * @return 0 if successful.
         */
        int printInfo() const;

        /**
         * @brief Get the total number of students.
         * 
         * @return The total number of students.
         */
        int getTotalStudents() const;

        /**
         * @brief Compare the grades of two students.
         * 
         * @param a The first student.
         * @param b The second student.
         * @return True if the grade of student a is greater than the grade of student b.
         */
        friend bool compareGrades(const Student& a, const Student& b);

        /**
         * @brief Print the courses of the student.
         * 
         * @return 0 if successful.
         */
        int printCourses() const;

        /**
         * @brief Enroll the student in a course.
         * 
         * @param course The course to enroll the student in.
         * @return 0 if successful.
         */
        int enroll(Course course);
        
    private:
        /**
         * @brief Compare two students for equality.
         * 
         * @param other The other student to compare.
         * @return True if the students are equal.
         */
        std::vector<Student::Course> courses;

        /**
         * @brief Generate random student information.
         */
        const void generateStudentInfo();
       
    };

    /**
     * @brief Compare the grades of two students.
     * 
     * @param a The first student.
     * @param b The second student.
     * @return True if the grade of student a is greater than the grade of student b.
     */
    bool compareGrades(const Student& a, const Student& b);

}


namespace detail {

    /**
     * @class RandomGenerator
     * @brief Provides functionality to generate random numbers and names.
     * 
     * The RandomGenerator class provides functionality to generate random numbers and names.
     */
    class RandomGenerator {

        static std::random_device rd;
        static std::mt19937 rng;

    public:

    /**
     * @brief Get a random number between min and max.
     * 
     * @tparam T The type of the number (float or integer).
     * @param min The minimum value.
     * @param max The maximum value.
     * @return A random number between min and max.
     * 
     * @note This method uses template metaprogramming to handle both floating point and integer types.
     */
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

        /**
         * @brief Generate a random name.
         * 
         * @return A random name.
         * 
         * @note this method uses getRandomNumber() to get a random index from the names vector.
         */

        static std::string generateRandomName();
    };
}