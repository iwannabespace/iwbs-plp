#ifndef LINE_HPP
#define LINE_HPP

#include "token.hpp"
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
            size_t getLineNumber() const;
            size_t getNumberOfTokens() const;
            bool contains(const Token& token) const;
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
    };
}

#endif