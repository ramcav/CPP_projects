#include <iostream>
#include "dyn_array.h"

// Quick testing created by CHAT GPT

int main() {
    try {
        // Test default constructor
        std::cout << "Testing default constructor\n";
        oop_practice3::DynamicArray array1;
        array1.setElementAt(0, 5);
        std::cout << "array1[0] = " << array1.getElementAt(0) << std::endl;

        // Test parameterized constructor (array initialization)
        std::cout << "\nTesting parameterized constructor with size\n";
        oop_practice3::DynamicArray array2(5);
        for (int i = 0; i < 5; ++i) {
            array2.setElementAt(i, i * 2);  // Set values to multiples of 2
        }
        for (int i = 0; i < 5; ++i) {
            std::cout << "array2[" << i << "] = " << array2.getElementAt(i) << std::endl;
        }

        // Test parameterized constructor with value initialization
        std::cout << "\nTesting parameterized constructor with size and initial value\n";
        oop_practice3::DynamicArray array3(5, 7);
        for (int i = 0; i < 5; ++i) {
            std::cout << "array3[" << i << "] = " << array3.getElementAt(i) << std::endl;
        }

        // Test parameterized constructor with pointer array
        std::cout << "\nTesting parameterized constructor with size and head pointer\n";
        int data[] = { 1, 2, 3, 4, 5 };
        oop_practice3::DynamicArray array4(5, data);
        for (int i = 0; i < 5; ++i) {
            std::cout << "array4[" << i << "] = " << array4.getElementAt(i) << std::endl;
        }

        // Test access (both constant and modifying)
        std::cout << "Accessing the first element of array4: " << array4[0] << std::endl;
        array4[0] = 5;
        std::cout << "Accessing the first element of array4 (should be 5 now): " << array4[0] << std::endl;

        // Test copy constructor
        std::cout << "\nTesting copy constructor\n";
        oop_practice3::DynamicArray array5 = array4;
        array5.setElementAt(0, 99);  // Modify copy, original should not change
        std::cout << "array5[0] (after modification) = " << array5.getElementAt(0) << std::endl;
        std::cout << "array4[0] (original, should not change) = " << array4.getElementAt(0) << std::endl;

        // Test move constructor
        std::cout << "\nTesting move constructor\n";
        oop_practice3::DynamicArray array6 = std::move(array5);  // Move ownership to array6
        std::cout << "array6[0] = " << array6.getElementAt(0) << std::endl;

        // Test move assignment operator
        std::cout << "\nTesting move assignment operator\n";
        oop_practice3::DynamicArray array7;
        array7 = std::move(array6);  // Move ownership to array7
        std::cout << "array7[0] = " << array7.getElementAt(0) << std::endl;

        // Now test the + operator
        std::cout << "\nTesting the + operator for array concatenation\n";
        oop_practice3::DynamicArray array8(3, 10);  // Array of size 3 with all elements set to 10
        oop_practice3::DynamicArray array9(2, 20);  // Array of size 2 with all elements set to 20

        // Concatenate array8 and array9
        oop_practice3::DynamicArray array10 = array8 + array9;

        // Print the elements of the concatenated array
        std::cout << "Concatenated array (array8 + array9):\n";
        for (int i = 0; i < array10.getSize(); ++i) {
            std::cout << "array10[" << i << "] = " << array10[i] << std::endl;
        }

         // Try out-of-bounds access
        std::cout << "\nTesting out-of-bounds access\n";
        array7.getElementAt(100);  // Should throw an exception


    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
