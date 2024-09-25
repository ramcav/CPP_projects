#include <gtest/gtest.h>
#include <list>
#include <string>
#include "dyn_array.h"
#include <vector>

namespace oop_test2{

    TEST(OOP_DYN, TestConstructors) {
        oop_practice3::DynamicArray arr1;
        oop_practice3::DynamicArrayVector arr2;

        ASSERT_EQ(arr1.getSize(), 10);
        ASSERT_EQ(arr2.getSize(), 10);

        delete[] arr1.getHead();

        oop_practice3::DynamicArray arr3(5);
        oop_practice3::DynamicArrayVector arr4(5);

        ASSERT_EQ(arr3.getSize(), 5);
        ASSERT_EQ(arr4.getSize(), 5);

        delete[] arr3.getHead();

        oop_practice3::DynamicArray arr5(5, 7);
        oop_practice3::DynamicArrayVector arr6(5, 7);

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr5.getElementAt(i), 7);
            ASSERT_EQ(arr6[i], 7);
        }

        delete[] arr5.getHead();

        oop_practice3::DynamicArray arr7(5, new int[5]{1, 2, 3, 4, 5});

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr7.getElementAt(i), i + 1);
        }

        oop_practice3::DynamicArray arr8(arr7);

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr8.getElementAt(i), i + 1);
        }

        oop_practice3::DynamicArray arr9(std::move(arr8));

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr9.getElementAt(i), i + 1);
        }

        oop_practice3::DynamicArray arr10;
        arr10 = std::move(arr9);

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr10.getElementAt(i), i + 1);
        }

        delete[] arr10.getHead();
        delete[] arr9.getHead();
        delete[] arr8.getHead();
        delete[] arr7.getHead();
    }
}