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
            VariableContainer(const std::vector<Variable>& variables);
            ~VariableContainer();
            bool pushVariable(const Variable& variable);
            Variable& operator[](const std::string& name);
            const Variable& operator[](const std::string& name) const;
        private:
            std::vector<Variable> variables;
    };
}

#endif