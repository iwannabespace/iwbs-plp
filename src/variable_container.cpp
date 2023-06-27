#include "../include/variable_container.hpp"

namespace iwbs
{
    VariableContainer::VariableContainer()
    {
    }

    VariableContainer::~VariableContainer()
    {
    }

    size_t VariableContainer::size() const
    {
        return variables.size();
    }

    bool VariableContainer::pushVariable(const Variable &variable)
    {
        for (size_t i = 0; i < variables.size(); i++)
            if (variables[i] == variable)
                return false;

        variables.push_back(variable);
        return true;
    }

    Variable &VariableContainer::operator[](size_t index)
    {
        if (index < 0 || index >= variables.size())
            throw "Index out of bounds for VariableContainer::variables container";
        
        return variables[index];
    }

    const Variable &VariableContainer::operator[](size_t index) const
    {
        if (index < 0 || index >= variables.size())
            throw "Index out of bounds for VariableContainer::variables container";
        
        return variables[index];
    }
}