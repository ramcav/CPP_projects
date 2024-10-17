

namespace homework {

    /**
    * @brief A class template that holds two values of any type.
    * @tparam T The type of the first value.
    * @tparam U The type of the second value.
    */

    template <typename T, typename U>
    struct Pair {
        T first;
        U second; 
    };
}