#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string>

namespace iwbs
{
    class Variable
    {
        public:
            enum class Type
            {
                Integer,
                Float,
                String,
                Boolean,
                Void,
                Unknown
            };
        public:
            Variable();
            Variable(Type type, const std::string& name, const std::string& value);
            ~Variable();
            void setType(Type type);
            void setName(const std::string& name);
            void setValue(const std::string& value);
            Type getType() const;
            const std::string& getName() const;
            const std::string& getValue() const;
            bool operator==(const Variable& rhs) const;
            bool operator!=(const Variable& rhs) const;
        private:
            Type type;
            std::string name;
            std::string value;
    };
}

#endif