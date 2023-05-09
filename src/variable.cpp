#include "../include/variable.hpp"

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
}