#include <gtest/gtest.h>
#include <list>
#include <string>
#include "dyn_array.h"
#include <vector>

namespace oop_test2{

    TEST(OOP_DYN, TestDefaultConstructor) {
        oop_practice3::DynamicArray arr1;
        oop_practice3::DynamicArrayVector arr2;

        ASSERT_EQ(arr1.getSize(), 10);
        ASSERT_EQ(arr2.getSize(), 10);
    }

    TEST(OOP_DYN, TestSizeConstructor) {
        oop_practice3::DynamicArray arr3(5);
        oop_practice3::DynamicArrayVector arr4(5);

        ASSERT_EQ(arr3.getSize(), 5);
        ASSERT_EQ(arr4.getSize(), 5);
    }

    TEST(OOP_DYN, TestValueConstructor) {
        oop_practice3::DynamicArray arr5(5, 7);
        oop_practice3::DynamicArrayVector arr6(5, 7);

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr5.getElementAt(i), 7);
            ASSERT_EQ(arr6[i], 7);
        }
    }

    TEST(OOP_DYN, TestArrayConstructor) {
        oop_practice3::DynamicArray arr7(5, new int[5]{1, 2, 3, 4, 5});

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr7.getElementAt(i), i + 1);
        }
    }

    TEST(OOP_DYN, TestCopyConstructor) {
        oop_practice3::DynamicArray arr7(5, new int[5]{1, 2, 3, 4, 5});
        oop_practice3::DynamicArray arr8(arr7);

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr8.getElementAt(i), i + 1);
        }
    }

    TEST(OOP_DYN, TestMoveConstructor) {
        oop_practice3::DynamicArray arr7(5, new int[5]{1, 2, 3, 4, 5});
        oop_practice3::DynamicArray arr9(std::move(arr7));

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr9.getElementAt(i), i + 1);
        }
    }

    TEST(OOP_DYN, TestMoveAssignmentOperator) {
        oop_practice3::DynamicArray arr7(5, new int[5]{1, 2, 3, 4, 5});
        oop_practice3::DynamicArray arr10;
        arr10 = std::move(arr7);

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr10.getElementAt(i), i + 1);
        }
    }

    TEST(OOP_DYN, TestSetElement) {
        oop_practice3::DynamicArray arr11(5, new int[5]{1, 2, 3, 4, 5});
        oop_practice3::DynamicArrayVector arr12(5, 7);

        arr11.setElementAt(2, 7);
        ASSERT_EQ(arr11.getElementAt(2), 7);

        arr11[3] = 7;
        ASSERT_EQ(arr11.getElementAt(3), 7);


        arr12[2] = 7;
        ASSERT_EQ(arr12[2], 7);

        arr12.setElementAt(3, 7);
        ASSERT_EQ(arr12[3], 7);

        
    }

    TEST(OOP_DYN, TestPlusOperator) {
        oop_practice3::DynamicArray arr13(5, new int[5]{1, 2, 3, 4, 5});
        oop_practice3::DynamicArray arr14(5, new int[5]{6, 7, 8, 9, 10});

        oop_practice3::DynamicArray arr15 = arr13 + arr14;

    
        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr15[i], arr13[i]);
        }

        for (int i = 5; i < 10; ++i) {
            ASSERT_EQ(arr15[i], arr14[i - 5]);
        }
    }

    TEST(OOP_DYN, TestPlusOperatorVector) {
        oop_practice3::DynamicArrayVector arr16(5, 1);
        oop_practice3::DynamicArrayVector arr17(5, 2);

        oop_practice3::DynamicArrayVector arr18 = arr16 + arr17;

        for (int i = 0; i < 5; ++i) {
            ASSERT_EQ(arr18[i], arr16[i]);
        }

        for (int i=5; i < 10; ++i) {
            ASSERT_EQ(arr18[i], arr17[i - 5]);
        }
    }


}