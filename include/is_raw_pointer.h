namespace homework {
    
    /**
     * @brief Metafunction to determine if a type is a raw pointer
     * @tparam T The type to check
     * @return true if T is a raw pointer, false otherwise
     */
    template <typename T>
    struct IsRawPointer {
        static constexpr bool value = false;
    };

    /**
     * @brief Metafunction specialization for raw pointers
     * @tparam T The type to check
     * @return true if T is a raw pointer, false otherwise
     */
    template <typename T>
    struct IsRawPointer<T*> {
        static constexpr bool value = true;
    };

    /**
     * @brief Convenience variable template for IsRawPointer::value
     * @tparam T The type to check
     */
    template <typename T>
    constexpr bool IsRawPointer_v = IsRawPointer<T>::value;
}