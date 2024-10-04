#include "expression.h"
#include <string>
#include <iostream>

namespace inheritance {

    Constant::Constant(double in_value) : value(in_value) {}

    double Constant::evaluate() const {
        return this->value;
    }

    Constant::operator std::string() const {
        return this->toString();
    }

    std::string Constant::toString() const {
        return std::to_string(this->value);
    }

    double Constant::setValue(double new_value) {
        this->value = new_value;
        return new_value;
    }

    double Constant::getValue() const {
        return this->value;
    }

    BinaryPlus::operator std::string() const {
        return this->toString();
    }

    BinaryPlus::BinaryPlus(const Expression& lhs, const Expression& rhs) 
        : member_1(lhs), member_2(rhs) {}

    double BinaryPlus::evaluate() const {
        return member_1.evaluate() + member_2.evaluate();
    }

    std::string BinaryPlus::toString() const {
        return "(" + member_1.toString() + " + " + member_2.toString() + ")";
    }

    void printExpression(const Expression& expr) {
        std::cout << expr.toString() << " = " << expr.evaluate() << std::endl;
    }

    void switchValue(Expression& expr, double value) {
        try {
            Constant& cast = dynamic_cast<Constant&>(expr);
            cast.setValue(value);
        } catch (const std::bad_cast& e) {
            throw std::invalid_argument("Expression is not of type Constant");
        }
    };

}
