#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <ostream>

namespace iwbs
{
    class Token
    {
        public:
            enum class Type
            {
                Unknown,
                Type,
                Identifier,
                Constant,
                Operator,
                Semicolon,
            };
        public:
            Token();
            Token(const std::string& value);
            Token(const std::string& value, Type type);
            ~Token();
            void setValue(const std::string& value);
            void setType(Type type);
            const std::string& getValue() const;
            Type getType() const;
        public:
            bool operator==(const Token& rhs) const;
            bool operator!=(const Token& rhs) const;
        public:
            friend std::ostream& operator<<(std::ostream& os, const Token& token);
            friend std::ostream& operator<<(std::ostream& os, Token::Type type);
        private:
            std::string value;
            Type type;
    };
}

#endif