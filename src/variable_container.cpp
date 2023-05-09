#include "../include/variable_container.hpp"

namespace iwbs
{
    VariableContainer::VariableContainer()
    {
    }

    VariableContainer::VariableContainer(const std::vector<Variable>& variables)
        : variables(variables)
    {
    }

    VariableContainer::~VariableContainer()
    {
    }

    bool VariableContainer::pushVariable(const Variable& variable)
    {
        for (const Variable& v : variables)
            if (v == variable)
                return false;
        
        variables.push_back(variable);
        return true;
    }

    Variable& VariableContainer::operator[](const std::string& name)
    {
        for (Variable& variable : variables)
            if (variable.getName() == name)
                return variable;
        
        throw "Variable couldn't be found";
    }

    const Variable& VariableContainer::operator[](const std::string& name) const
    {
        for (const Variable& variable : variables)
            if (variable.getName() == name)
                return variable;
        
        throw "Variable couldn't be found";
    }
}