#ifndef VARIABLE_CONTAINER_HPP
#define VARIABLE_CONTAINER_HPP

#include "variable.hpp"
#include <vector>

namespace iwbs
{
    class VariableContainer
    {
        public:
            VariableContainer();
            ~VariableContainer();
            size_t size() const;
            bool pushVariable(const Variable& variable);
            Variable& operator[](size_t index);
            const Variable& operator[](size_t index) const;
        private:
            std::vector<Variable> variables;
    };
}

#endif