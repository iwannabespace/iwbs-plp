#include "../include/token.hpp"

namespace iwbs
{
    Token::Token()
        : value(""), type(Type::Unknown)
    {
    }

    Token::Token(const std::string& value, Type type)
        : value(value), type(type)
    {
    }

    Token::~Token()
    {
    }

    void Token::setValue(const std::string& value)
    {
        this->value = value;
    }

    void Token::setType(Type type)
    {
        this->type = type;
    }

    const std::string& Token::getValue() const
    {
        return value;
    }

    Token::Type Token::getType() const
    {
        return type;
    }

    std::ostream& operator<<(std::ostream& os, const Token& token)
    {
        return os << token.getValue();
    }

    std::ostream& operator<<(std::ostream& os, Token::Type type)
    {
        switch (type)
        {
            case Token::Type::Unknown:
                os << "Unknown";
                break;
            case Token::Type::VariableType:
                os << "VariableType";
                break;
            case Token::Type::VariableName:
                os << "VariableName";
                break;
            case Token::Type::IntegerValue:
                os << "IntegerValue";
                break;
            case Token::Type::FloatValue:
                os << "FloatValue";
                break;
            case Token::Type::BooleanValue:
                os << "BooleanValue";
                break;
            case Token::Type::StringValue:
                os << "StringValue";
                break;
            case Token::Type::Operator:
                os << "Operator";
                break;
            case Token::Type::Function:
                os << "Function";
                break;
            case Token::Type::Semicolon:
                os << "Semicolon";
                break;
        }

        return os;
    }
}