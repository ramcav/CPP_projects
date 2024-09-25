#include <vector>
#include <stdexcept>

/**
 * @file dyn_array.h
 * @brief This file contains the declarations of the DynamicArray and DynamicArrayVector classes.
 */
namespace oop_practice3 {

    /**
     * @class DynamicArray
     * @brief Represents a dynamic array with a fixed size.
     * 
     * The DynamicArray class provides functionality to store and manipulate a dynamic array of integers using a pointer.
     */
    class DynamicArray {
        int size;
        int* head;
        // std::vector<int> elements;
    public:
        // Constructors
        /**
         * @brief Default constructor for the DynamicArray class.
         * 
         * Initializes the array with a default size of 10.
         */
        DynamicArray();

        /**
         * @brief Constructor for the DynamicArray class.
         * 
         * @param in_size The size of the array.
         * @param in_head The head pointer to the array.
         * 
         * Initializes the array with the given size and head pointer.
         */
        DynamicArray(int in_size, int* in_head);

        /**
         * @brief Constructor for the DynamicArray class.
         * 
         * @param other The other DynamicArray object to copy.
         * 
         * Initializes the array with the same size and elements as the other DynamicArray object.
         */
        DynamicArray(const DynamicArray& other);

        /**
         * @brief Move constructor for the DynamicArray class.
         * 
         * @param other The other DynamicArray object to move.
         * 
         * Initializes the array by moving the elements from the other DynamicArray object.
         */
        DynamicArray(DynamicArray&& other) noexcept;

        /**
         * @brief Constructor for the DynamicArray class.
         * 
         * @param in_size The size of the array.
         * 
         * Initializes the array with the given size and sets each element to 0.
         */
        DynamicArray(int in_size);

        /**
         * @brief Constructor for the DynamicArray class.
         * 
         * @param in_size The size of the array.
         * @param in_val The initial value for each element.
         * 
         * Initializes the array with the given size and sets each element to the initial value.
         */
        DynamicArray(int in_size, int in_val);

        // Destructor
        /**
         * @brief Destructor for the DynamicArray class.
         * 
         * Deallocates the memory used by the array.
         */
        ~DynamicArray();

        // Operator Overloads

        /**
         * @brief Overload the assignment operator.
         * 
         * @param other The other DynamicArray object to copy.
         * @return The copied DynamicArray object.
         */
        DynamicArray& operator=(DynamicArray&& other) noexcept;

        /**
         * @brief Overload the subscript operator.
         * 
         * @param index The index of the element to access.
         * @return The reference to the element at the given index.
         */
        int& operator[](int index);

        /**
         * @brief Overload the subscript operator.
         * 
         * @param index The index of the element to access.
         * @return The constant reference to the element at the given index.
         */
        const int& operator[](int index) const;

        /**
         * @brief Overload the addition operator.
         * 
         * @param lhs The left-hand side DynamicArray object.
         * @param rhs The right-hand side DynamicArray object.
         * @return The concatenated DynamicArray object.
         */
        friend DynamicArray operator+(const DynamicArray& lhs, const DynamicArray& rhs);

        // Getters
        /**
         * @brief Get the size of the array.
         * 
         * @return The size of the array.
         */
        int getSize() const;

        /**
         * @brief Get the head pointer of the array.
         * 
         * @return The head pointer of the array.
         */
        int* getHead() const;
        
        //const std::vector<int>& getElements() const;
        // std::vector<int>& getElements();

        // Additional methods

        /**
         * @brief Set an element in the array.
         * 
         * @param index The index of the element to set.
         * @param value The value to set the element to.
         */
        void setElementAt(int index, int value);

        /**
         * @brief Get an element from the array.
         * 
         * @param index The index of the element to get.
         * @return The element at the given index.
         */
        int getElementAt(int index) const;
    };

    /**
     * @class DynamicArrayVector
     * @brief Represents a dynamic array using a std::vector.
     * 
     * The DynamicArrayVector class provides functionality to store and manipulate a dynamic array of integers using a std::vector.
     */
    class DynamicArrayVector {
    std::vector<int> elements;
    public:
        // Constructors

        /**
         * @brief Default constructor for the DynamicArrayVector class.
         * 
         * Initializes the vector with a default size of 10.
         */
        DynamicArrayVector();

        /**
         * @brief Copy constructor for the DynamicArrayVector class.
         * 
         * @param other The other DynamicArrayVector object to copy.
         * 
         */
        DynamicArrayVector(const DynamicArrayVector& other);

        /**
         * @brief Move constructor for the DynamicArrayVector class.
         * 
         * @param other The other DynamicArrayVector object to move.
         * 
         */
        DynamicArrayVector(DynamicArrayVector&& other) noexcept;

        /**
         * @brief Constructor for the DynamicArrayVector class.
         * 
         * @param in_size The size of the vector.
         */
        DynamicArrayVector(int in_size);

        /**
         * @brief Constructor for the DynamicArrayVector class.
         * 
         * @param in_size The size of the vector.
         * @param in_val The initial value for each element.
         */
        DynamicArrayVector(int in_size, int in_val);

        // Destructor
        /**
         * @brief Destructor for the DynamicArrayVector class.
         */
        ~DynamicArrayVector() = default;

        // Operator Overloads
        /**
         * @brief Overload the move assignment operator.
         * 
         * @param other The other DynamicArrayVector object to move.
         * @return The moved DynamicArrayVector object.
         */
        DynamicArrayVector& operator=(DynamicArrayVector&& other) noexcept;

        /**
         * @brief Overload the subscript operator.
         * 
         * @param index The index of the element to access.
         * @return The reference to the element at the given index.
         */
        int& operator[](int index);

        /**
         * @brief Overload the subscript operator.
         * 
         * @param index The index of the element to access.
         * @return The constant reference to the element at the given index.
         */ 
        const int& operator[](int index) const;

        /**
         * @brief Overload the addition operator.
         * 
         * @param lhs The left-hand side DynamicArrayVector object.
         * @param rhs The right-hand side DynamicArrayVector object.
         * @return The concatenated DynamicArrayVector object.
         */
        friend DynamicArrayVector operator+(const DynamicArrayVector& lhs, const DynamicArrayVector& rhs);

        // Getters

        /**
         * @brief Get the size of the vector.
         * 
         * @return The size of the vector.
         */
        int getSize() const;

        /**
         * @brief Get the elements of the vector.
         * 
         * @return The elements of the vector.
         * 
         * @note This is a const version of the getElements method.
         */
        const std::vector<int>& getElements() const;

        /**
         * @brief Get the elements of the vector.
         * 
         * @return The elements of the vector.
         * 
         * @note This is a non-const version of the getElements method.
         */
        std::vector<int>& getElements();

        // Additional methods

        /**
         * @brief Set an element in the vector.
         * 
         * @param index The index of the element to set.
         * @param value The value to set the element to.
         */
        void setElementAt(int index, int value);

        /**
         * @brief Get an element from the vector.
         * 
         * @param index The index of the element to get.
         * @return The element at the given index.
         */
        int getElementAt(int index) const;
    };

}