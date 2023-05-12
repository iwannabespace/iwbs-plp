#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include "variable.hpp"

namespace iwbs
{
    class Operator
    {
        public:
            static bool Assignment(const Variable& variable);
            static bool Addition(const Variable& lhs, const Variable& rhs);
            static bool Subtraction(const Variable& lhs, const Variable& rhs);
            static bool Multiplication(const Variable& lhs, const Variable& rhs);
            static bool Division(const Variable& lhs, const Variable& rhs);
    };
}

#endif