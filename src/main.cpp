#include "expression.h"
#include <iostream>
#include <cassert>
#include <vector>

int main() {
    // Inheritance in action.
    //Constant and BinaryPlus are both children of Expression
    // inheritance::Constant c1(1);
    // inheritance::Constant c2(2);
    // inheritance::Constant c3(3);
    // inheritance::BinaryPlus bp(c1, c2);
    // inheritance::BinaryPlus bp2(bp, c3);
    // std::string c1plusc2plusc3 = bp2.toString();
    // double result = bp2.evaluate();
    // std::cout << c1plusc2plusc3 << " = " << result << std::endl; 
    // assert(result == 6);

    // // Polymorphism in action

    // std::vector<const inheritance::Expression*> expressions = {&c1, &c2, &c3, &bp, &bp2};
    // for (const inheritance::Expression* e_ptr : expressions) {

    //     const inheritance::Expression& e = *e_ptr;

    //     inheritance::printExpression(e);

    // }

    inheritance::Constant c1(1);
    inheritance::Constant c2(2);

    std::cout<<"EVALUATE:" <<c1.evaluate()<<std::endl;
    std::cout<<"TO-STRING:" <<c2.toString()<<std::endl;

    inheritance::BinaryPlus bp(c1, c2);
    std::string c1plusc2 = static_cast<std::string>(bp);

    std::cout << c1plusc2 << std::endl;

    inheritance::switchValue(bp, 2);

    return 0;
}