#include "../include/token.hpp"

namespace iwbs
{
    Token::Token()
        : value(""), type(Type::Unknown)
    {
    }

    Token::Token(const std::string& value)
        : value(value), type(Token::Type::Unknown)
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

    bool Token::operator==(const Token& rhs) const
    {
        return value == rhs.value && type == rhs.type;
    }

    bool Token::operator!=(const Token& rhs) const
    {
        return !(*this == rhs);
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
            case Token::Type::Type:
                os << "Type";
                break;
            case Token::Type::Identifier:
                os << "Identifier";
                break;
            case Token::Type::Constant:
                os << "Constant";
                break;
            case Token::Type::Operator:
                os << "Operator";
                break;
            case Token::Type::Semicolon:
                os << "Semicolon";
                break;
        }

        return os;
    }
}