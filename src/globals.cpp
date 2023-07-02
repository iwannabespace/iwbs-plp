#include "../include/globals.hpp"
#include <iostream>

namespace iwbs::Globals
{
    std::vector<std::string> Split(const std::string& str, const std::string& delim)
    {
        std::vector<std::string> result;
        size_t start = 0;
        size_t end = 0;

        if (str.find(delim) == std::string::npos)
            return std::vector<std::string>{};

        while ((end = str.find(delim, start)) != std::string::npos)
        {
            result.push_back(str.substr(start, end - start));
            start = end + delim.length();
        }

        std::string lastToken = str.substr(start);

        if (!lastToken.empty())
            result.push_back(lastToken);

        return result;
    }

    std::string GetRange(size_t startIndex, uint8_t endChar, const std::string& str)
    {
        return str.substr(startIndex, str.find(endChar, startIndex + 1) - (startIndex - 1));
    }

    bool IsKeyword(const std::string& str)
    {
        using namespace Keywords;

        return std::any_of(KEYWORDS.begin(), KEYWORDS.end(), [&str](const std::string& keyword) {
            return str == keyword;
        });
    }

    bool IsValidIdentifier(const std::string& name)
    {
        bool startsWithAlpha = std::isalpha(name.front()) || name.front() == '_';

        bool namingValid = std::all_of(name.begin() + 1, name.end(), [](char c) {
             return std::isalpha(c) || std::isdigit(c) || c == '_'; 
        });

        bool keyword = IsKeyword(name);

        return startsWithAlpha && namingValid && !keyword;
    }

    Variable::Type ResolveVariableType(const std::string& value)
    {
        if (value == "integer")
            return Variable::Type::Integer;
        
        if (value == "float")
            return Variable::Type::Float;
        
        if (value == "string")
            return Variable::Type::String;
        
        if (value == "boolean")
            return Variable::Type::Boolean;
        
        if (value == "void")
            return Variable::Type::Void;
        
        return Variable::Type::Unknown;
    }

    Token::Type ResolveTokenType(const std::string& value)
    {
        if (ResolveVariableType(value) != Variable::Type::Unknown)
            return Token::Type::VariableType;

        if (IsIntegerConstant(value))
            return Token::Type::IConstant;
        
        if (IsFloatConstant(value))
            return Token::Type::FConstant;

        if (IsStringConstant(value))
            return Token::Type::SConstant;

        if (IsBooleanConstant(value))
            return Token::Type::BConstant;
        
        if (value == "as")
            return Token::Type::Operator;

        return Token::Type::Identifier;
    }

    std::variant<int64_t, Error> ConvertToInteger(const std::string& str)
    {
        bool isInteger = IsIntegerConstant(str);

        if (isInteger)
            return std::stoll(str);
        else 
            return Error();
    }

    // Test this
    std::variant<double, Error> ConvertToFloat(const std::string& str)
    {
        bool isFloat = IsFloatConstant(str);

        if (isFloat)
            return std::stod(str);
        else
            return Error();
    }

    std::variant<std::string, Error> ConvertToString(const std::string& str)
    {
    }

    // Test this
    std::variant<bool, Error> ConvertToBoolean(const std::string& str)
    {
        bool isBoolean = IsBooleanConstant(str);

        if (isBoolean)
            return str == "true";
        else
            return Error();
    }

    bool IsConstant(const std::string& str)
    {
        return IsIntegerConstant(str) || IsFloatConstant(str) || 
                IsStringConstant(str) || IsBooleanConstant(str);
    }

    bool IsIntegerConstant(const std::string& str)
    {
        bool fchar = (str.front() == '+' || str.front() == '-' || std::isdigit(str.front()));

        bool integer = std::all_of(str.begin() + 1, str.end(), [](char c) {
            return std::isdigit(c);
        });

        return integer && fchar;
    }

    bool IsFloatConstant(const std::string& str)
    {
        char fChar = str.front();
        auto numberOfDots = std::count(str.begin(), str.end(), '.');
        bool anyWrongChar = std::any_of(str.begin(), str.end(), [](char c) {
            return (c != '.') && std::isalpha(c);
        });

        if (fChar == '-' || fChar == '+')
        {
            if (str.length() <= 3)
                return false;

            if (!std::isdigit(str[1]) || !std::isdigit(str.back()) || numberOfDots != 1 || anyWrongChar)
                return false;
            
            return true;
        }

        else if (std::isdigit(fChar))
        {
            if (str.length() < 3) 
                return false;
            
            if (!std::isdigit(fChar) || !std::isdigit(str.back()) || numberOfDots != 1 || anyWrongChar)
                return false;

            return true;
        }

        return false;
    }

    bool IsStringConstant(const std::string& str)
    {
        bool containsQuote = std::any_of(str.begin() + 1, str.end() - 1, [](char c) {
            return c == '"';
        });

        return str.front() == '"' && str.back() == '"' && !containsQuote;
    }

    bool IsBooleanConstant(const std::string& str)
    {
        return str == "true" || str == "false";
    }
}