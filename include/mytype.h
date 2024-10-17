// include/mytype.h
#pragma once
#include <iostream>
#include <fstream>
namespace homework {
    /**
    * @brief A type with some members that can be serialized
    */
    class MyType {

        int i;
        double d;

        public:
            MyType(int i, double d) : i(i), d(d) {}

            /**
            * @brief Equality operator
            * @param other The MyType object to compare to
            * @return True if the objects are equal, false otherwise
            */
            auto operator==(const MyType& other) const {
                return i == other.i && d == other.d;
            }

            /**
             * @brief Plus-equal operator
             * @param other The MyType object to add to this object
             * @return A reference to this object
             * @details Adds the members of the other object to this object
             */
            auto operator+=(const MyType& other) {
                this->i += other.get_i();
                this->d += other.get_d();
                return *this;
            }

            /**
             * @brief Get the integer member
             * @return The integer member
             */
            int get_i() const {
                return this->i;
            }

            /**
             * @brief Get the double member
             * @return The double member
             */
            double get_d() const {
                return this->d;
            }

            /**
             * @brief Overload of the << operator for MyType
             * @param os The output stream to write to
             * @param mt The MyType object to write
             * @return os
             * @details Writes the integer and double members of the MyType object to the output stream
             * to be used in whatever way the output stream is being used
             */
            friend std::ostream& operator<<(std::ostream& os, const MyType& mt);

            friend std::istream& operator>>(std::istream& is, MyType& mt);
};

    std::ostream& operator<<(std::ostream& os, const MyType& mt) {
            os << mt.get_i() << " " << mt.get_d();
            return os;
    }

    std::istream& operator>>(std::istream& is, MyType& mt) {
        int i;
        double d;

        is >> i >> d;
        mt = MyType(i,d);

        return is;
    }

    /**
    * @brief Write the MyType object to a file
    * @param mt The MyType object to write
    * @param filename The name of the file to write to
    */
    void writeToFile(const MyType& mt, const std::string& filename) {
        // Write the MyType object to a file with the given filename
        std::ofstream file(filename);

        if (!file) {
            throw std::runtime_error("Error opening file " + filename);
        }

        file << mt;
    }

    /**
    * @brief Read the MyType object from a file
    * @param filename The name of the file to read from
    * @return The MyType object read from the file
    */
    MyType readFromFile(MyType& mt, const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error("Error opening file " + filename);
    }
        
    file >> mt;

    return mt;

    }
} // namespace homework