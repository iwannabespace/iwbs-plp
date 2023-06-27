#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "variable.hpp"
#include "token.hpp"
#include "keywords.hpp"
#include "error.hpp"
#include <vector>
#include <string>

namespace iwbs::Globals
{
    std::vector<std::string> Split(const std::string& str, const std::string& delim);
    std::string GetRange(size_t startIndex, uint8_t endChar, const std::string& str);
    bool IsKeyword(const std::string& str);
    bool IsValidIdentifier(const std::string& name);
    Variable::Type ResolveVariableType(const std::string& value);
    Token::Type ResolveTokenType(const std::string& value);
    std::variant<int64_t, bool> ConvertToInteger(const std::string& str);
    bool IsIntegerConstant(const std::string& str);
    bool IsFloatConstant(const std::string& str);
    bool IsStringConstant(const std::string& str);
    bool IsBooleanConstant(const std::string& str);
}

#endif