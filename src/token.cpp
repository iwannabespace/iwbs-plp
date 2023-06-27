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
            case Token::Type::VariableType:
                os << "VariableType";
                break;
            case Token::Type::Identifier:
                os << "Identifier";
                break;
            case Token::Type::IConstant:
                os << "IConstant";
                break;
            case Token::Type::FConstant:
                os << "FConstant";
                break;
            case Token::Type::SConstant:
                os << "SConstant";
                break;
            case Token::Type::BConstant:
                os << "BConstant";
                break;
            case Token::Type::OParan:
                os << "OParan";
                break;
            case Token::Type::CParan:
                os << "CParan";
                break;
            case Token::Type::OCurly:
                os << "OCurly";
                break;
            case Token::Type::CCurly:
                os << "CCurly";
                break;
            case Token::Type::OBracket:
                os << "OBracket";
                break;
            case Token::Type::CBracket:
                os << "CBracket";
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