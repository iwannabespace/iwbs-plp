#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>

namespace iwbs
{
    class Type
    {
        public:
            Type();
            Type(const std::string& value);
            void setValue(const std::string& value);
            const std::string& getValue();
            bool isValid() const;
        protected:
            std::string value;
            bool valid;
    };
}

#endif