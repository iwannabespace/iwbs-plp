#ifndef KEYWORDS_HPP
#define KEYWORDS_HPP

#include <vector>
#include <string>

namespace iwbs
{
    const std::vector<std::string> KEYWORDS = {
        "integer",
        "float",
        "string",
        "boolean",
        "if",
        "else if",
        "else",
        "function",
        "as",
    };

    bool IsKeyword(const std::string& str)
    {
        return std::any_of(KEYWORDS.begin(), KEYWORDS.end(), [&str](const std::string& keyword) {
            return str == keyword;
        });
    }
}

#endif