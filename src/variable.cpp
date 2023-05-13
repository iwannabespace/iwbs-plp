#include "../include/variable.hpp"
#include "../include/keywords.hpp"

namespace iwbs
{
    Variable::Variable()
        : type(Type::Unknown), name(""), value("")
    {   
    }

    Variable::Variable(Type type, const std::string& name, const std::string& value)
        : type(type), name(name), value(value)
    {
    }

    Variable::~Variable()
    {
    }

    void Variable::setType(Type type)
    {
        this->type = type;
    }

    void Variable::setName(const std::string& name)
    {
        this->name = name;
    }

    void Variable::setValue(const std::string& value)
    {
        this->value = value;
    }

    Variable::Type Variable::getType() const
    {
        return type;
    }

    const std::string& Variable::getName() const
    {
        return name;
    }

    const std::string& Variable::getValue() const
    {
        return value;
    }

    bool Variable::operator==(const Variable& rhs) const
    {
        return name == rhs.name;
    }

    bool Variable::operator!=(const Variable& rhs) const
    {
        return !(*this == rhs);
    }

    Variable::Type Variable::Resolve(const std::string& value)
    {
        if (value == "integer")
            return Type::Integer;
        
        if (value == "float")
            return Type::Float;
        
        if (value == "string")
            return Type::String;
        
        if (value == "boolean")
            return Type::Boolean;
        
        return Type::Unknown;
    }

    bool Variable::IsValidVariableName(const std::string& name)
    {
        bool startsWithAlpha = std::isalpha(name[0]) || name[0] == '_';

        bool namingValid = std::all_of(name.begin() + 1, name.end(), [](char c) {
             return std::isalpha(c) || std::isdigit(c) || c == '_'; 
        });

        bool keyword = std::any_of(KEYWORDS.begin(), KEYWORDS.end(), [&name](const std::string& keyword) {
            return keyword == name;
        });

        return startsWithAlpha && namingValid && !keyword;
    }
}