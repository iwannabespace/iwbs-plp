#include "../include/line.hpp"

namespace iwbs
{
    Line::Line()
        : lineNumber(0)
    {
    }

    Line::~Line()
    {
    }

    void Line::pushToken(const Token& token)
    {
        tokens.push_back(token);
    }

    void Line::setLineNumber(size_t lineNumber)
    {
        this->lineNumber = lineNumber;
    }

    void Line::setError(const Error& error)
    {
        this->error = error;
    }

    size_t Line::getLineNumber() const
    {
        return lineNumber;
    }

    size_t Line::getNumberOfTokens() const
    {
        return tokens.size();
    }
    
    const Error& Line::getError() const
    {
        return error;
    }

    bool Line::contains(const Token& token) const
    {
        for (const Token& t : tokens)
            if (t.getValue() == token.getValue() && t.getType() == token.getType())
                return true;

        return false;
    }

    bool Line::contains(const std::string& tokenValue) const
    {
        for (const Token& t : tokens)
            if (t.getValue() == tokenValue)
                return true;

        return false;
    }

    uint32_t Line::count(const Token& token) const
    {
        int32_t result = 0;

        for (const Token& t : tokens)
            if (t == token)
                result++;

        return result;
    }
    
    uint32_t Line::count(const std::string& tokenValue) const
    {
        int32_t result = 0;

        for (const Token& t : tokens)
            if (t.getValue() == tokenValue)
                result++;

        return result;
    }

    void Line::clear()
    {
        tokens.clear();
        lineNumber = 0;
    }

    const Token& Line::operator[](size_t index) const
    {
        if (index < 0 || index >= tokens.size())
            throw "Index out of bounds for Line::tokens container";

        return tokens[index];
    }

    Token& Line::operator[](size_t index)
    {
        if (index < 0 || index >= tokens.size())
            throw "Index out of bounds for Line::tokens container";

        return tokens[index];
    }

    Token* Line::begin()
    {
        return &tokens[0];
    }

    Token* Line::end()
    {
        return &tokens[tokens.size()];
    }

    const Token* Line::begin() const
    {
        return &tokens[0];
    }
    
    const Token* Line::end() const
    {
        return &tokens[tokens.size()];
    }

    std::ostream& operator<<(std::ostream& os, const Line& line)
    {
        for (const Token& token : line)
            os << token << " ";

        return os;
    }   
}