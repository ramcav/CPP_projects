// include/sum.h
#pragma once
#include <vector>
#include <tuple>
#include <iostream>
#include <tuple>
namespace homework{
    /**
    * @brief Metafunction for summing the elements of a vector holding elements of any type
    * @param s The vector to sum
    * @param v The initial value of the sum
    * @tparam T The type of the elements in the vector
    * @tparam Container The type of container the elements are held in
    * @return The sum of the elements in the vector, plus the initial value
    */
    template <typename T, typename Container>
    T sum_elements(Container& s, T v) {
        for (T n: s) {
            v += n;
        }

        return v;
    }
    /**
    * @brief Metafunction specification for summing the elements of a vector holding string
    * @param s The vector to sum
    * @param v The initial value of the sum
    * @return The sum of the elements in the vector, plus the initial value
    */
    template <>
    std::string sum_elements(std::vector<std::string>& s, std::string v) {
        for (std::string str: s) {
            v += str;
        }
        return v;
    }

    /**
     * @brief function to make a tuple of any number of arguments
     * @param args The arguments to make the tuple from
     * @tparam Args The types of the arguments
     * @return The tuple of the arguments
     */
    template<typename... Args>
    auto make_tuple(Args... args) {
        return std::make_tuple(args...);
    }

    
// Define here your function
}; // namespace homework