#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "variable.hpp"
#include "token.hpp"
#include "line.hpp"
#include "keywords.hpp"
#include "error.hpp"
#include <vector>
#include <string>
#include <optional>

namespace iwbs::Globals
{
    std::vector<std::string> Split(const std::string& str, const std::string& delim);
    std::string GetRange(size_t startIndex, uint8_t endChar, const std::string& str);
    bool IsKeyword(const std::string& str);
    bool IsValidIdentifier(const std::string& name);
    Variable::Type ResolveVariableType(const std::string& value);
    Token::Type ResolveTokenType(const std::string& value);
    std::optional<int64_t> ConvertToInteger(const std::string& str);
    std::optional<double> ConvertToFloat(const std::string& str);
    std::optional<std::string> ConvertToString(const std::string& str);
    std::optional<bool> ConvertToBoolean(const std::string& str);
    bool IsConstant(const std::string& str);
    bool IsIntegerConstant(const std::string& str);
    bool IsFloatConstant(const std::string& str);
    bool IsStringConstant(const std::string& str);
    bool IsBooleanConstant(const std::string& str);
    Line Evaluate(const Line& line);
    // Token ConvertIntegerTokenToFloat(const Token& token);
    // Token ConvertIntegerTokenToString(const Token& token);
    // Token ConvertIntegerTokenToBoolean(const Token& token);
    // Token ConvertFloatTokenToInteger(const Token& token);
    // Token ConvertFloatTokenToString(const Token& token);
    // Token ConvertFloatTokenToBoolean(const Token& token);
    // Token ConvertStringTokenToInteger(const Token& token);
    // Token ConvertStringTokenToFloat(const Token& token);
    // Token ConvertStringTokenToBoolean(const Token& token);
    // Token ConvertBooleanTokenToInteger(const Token& token);
    // Token ConvertBooleanTokenToFloat(const Token& token);
    // Token ConvertBooleanTokenToString(const Token& token);
}

#endif