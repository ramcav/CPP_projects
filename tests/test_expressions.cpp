#include <gtest/gtest.h>
#include <list>
#include <string>
#include "expression.h"
#include <vector>

namespace expressions_test {

    TEST(EXP, TestConstant) {
        inheritance::Constant c(1);

        ASSERT_EQ(c.getValue(), 1);
    }

    TEST(EXP, TestConstantSetter) {
        inheritance::Constant c(1);

        c.setValue(2);
        ASSERT_EQ(c.evaluate(), 2);
        ASSERT_EQ(c.toString(), "2.000000");
    }

    TEST(EXP, TestConstantCast) {
        inheritance::Constant c(1);
        ASSERT_EQ(static_cast<std::string>(c), "1.000000");
    }

    TEST(EXP, TestBinaryPlus) {
        inheritance::Constant c1(1);
        inheritance::Constant c2(2);
        inheritance::BinaryPlus bp(c1, c2);

        ASSERT_EQ(bp.evaluate(), 3);
        ASSERT_EQ(bp.toString(), "(1.000000 + 2.000000)");
    }

    TEST(EXP, TestFunction) {
    inheritance::Constant c1(1);
    inheritance::Constant c2(2);
    inheritance::BinaryPlus bp(c1, c2);

    ASSERT_THROW(inheritance::switchValue(bp, 2), std::invalid_argument);
    
    ASSERT_NO_THROW(inheritance::switchValue(c1, 2));
    }
}
