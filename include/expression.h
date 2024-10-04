#pragma once

#include <string>

namespace inheritance {

    /**
     * @brief An abstract class representing an expression.
     */

    class Expression {
    public:
        /**
         * @brief Returns a string representation of the expression.
         * 
         * @return std::string
         * 
         * @note This is a pure virtual function.
         */
        virtual std::string toString() const = 0; 

        /**
         * @brief Evaluates the expression.
         * 
         * @return double
         * 
         * @note This is a pure virtual function.
         */
        virtual double evaluate() const = 0;

        /**
         * @brief Destructor for the Expression class.
         */
        virtual ~Expression() = default;

        /**
         * @brief Converts the expression to a string.
         * 
         * @return std::string
         * 
         * @note This is a pure virtual function.
         */
        virtual operator std::string() const = 0;
    };

    /**
     * @brief A class representing a constant expression.
     * 
     * @note This class inherits from the Expression class.
     */
    class Constant : public Expression {
        double value;
    public:
        /**
         * @brief Constructor for the Constant class.
         * 
         * @param value The value of the constant.
         */
        Constant(double value);

        /**
         * @brief Returns a string representation of the constant.
         * 
         * @return std::string
         */
        std::string toString() const override;

        /**
         * @brief Evaluates the constant.
         * 
         * @return double
         */  
        double evaluate() const override;

        /**
         * @brief Sets the value of the constant.
         * 
         * @param new_value The new value of the constant.
         * 
         * @return double
         */
        double setValue(double new_value);

        /**
         * @brief Returns the value of the constant.
         * 
         * @return double
         */
        double getValue() const;

        /**
         * @brief Converts the constant to a string.
         * 
         * @return std::string
         */
        operator std::string() const override;
        
    };

    /**
     * @brief A class representing a plus expression between two types of Expressions.
     * 
     * @note This class inherits from the Expression class.
     */
    class BinaryPlus : public Expression {
        const Expression& member_1;
        const Expression& member_2;
    public:
        /**
         * @brief Constructor for the BinaryPlus class.
         * 
         * @param lhs The left hand side expression.
         * @param rhs The right hand side expression.
         */
        BinaryPlus(const Expression& lhs, const Expression& rhs);

        /**
         * @brief Returns a string representation of the plus expression.
         * 
         * @return std::string
         */
        std::string toString() const override;

        /**
         * @brief Evaluates the plus expression.
         * 
         * @return double
         */
        double evaluate() const override;

        /**
         * @brief Converts the plus expression to a string.
         * 
         * @return std::string
         */
        operator std::string() const override;
        
    };

    /**
     * @brief Prints the expression and its evaluation.
     * 
     * @param expr The expression to print.
     * 
     * @note This function will not work if a parameter different of type Constant is passed.
     */

    void switchValue(Expression &expr, double value);

    /**
     * @brief Prints the expression and its evaluation.
     * 
     * @param expr The expression to print.
     */
    void printExpression(const Expression& expr);
}