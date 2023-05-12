#include "../../include/types/type.hpp"

namespace iwbs
{
    Type::Type()
        : valid(false)
    {
    }

    Type::Type(const std::string& value)
    {
        
    }

    void Type::setValue(const std::string& value)
    {

    }

    const std::string& Type::getValue()
    {
        return value;
    }

    bool Type::isValid() const
    {
        return valid;
    }
}