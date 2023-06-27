#ifndef LINE_HPP
#define LINE_HPP

#include "token.hpp"
#include "error.hpp"
#include <vector>

namespace iwbs
{
    class Line
    {
        public:
            Line();
            ~Line();
            void pushToken(const Token& token);
            void setLineNumber(size_t lineNumber);
            void setError(const Error& error);
            size_t getLineNumber() const;
            size_t getNumberOfTokens() const;
            const Error& getError() const;
            bool empty() const;
            bool contains(const Token& token) const;
            bool contains(const std::string& tokenValue) const;
            uint32_t count(const Token& token) const;
            uint32_t count(const std::string& tokenValue) const;
            void clear();
            const Token& operator[](size_t index) const;
            Token& operator[](size_t index);
        public:
            Token* begin();
            Token* end();
            const Token* begin() const;
            const Token* end() const;
        public:
            friend std::ostream& operator<<(std::ostream& os, const Line& line);
        private:
            std::vector<Token> tokens;
            size_t lineNumber;
            Error error;
    };
}

#endif