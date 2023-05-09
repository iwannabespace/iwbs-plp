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
                VariableType,
                VariableName,
                IntegerValue,
                FloatValue,
                BooleanValue,
                StringValue,
                Operator,
                Function,
                Semicolon,
            };
        public:
            Token();
            Token(const std::string& value, Type type);
            ~Token();
            void setValue(const std::string& value);
            void setType(Type type);
            const std::string& getValue() const;
            Type getType() const;
        public:
            friend std::ostream& operator<<(std::ostream& os, const Token& token);
            friend std::ostream& operator<<(std::ostream& os, Token::Type type);
        private:
            std::string value;
            Type type;
    };
}

#endif