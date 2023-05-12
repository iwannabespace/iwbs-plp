#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

namespace iwbs
{
    class Error
    {
        public:
            Error();
            Error(const std::string& message, size_t lineNumber);
            ~Error();
            void setMessage(const std::string& message);
            void setLineNumber(size_t lineNumber);
            const std::string& getMessage() const;
            size_t getLineNumber() const;
        private:
            std::string message;
            size_t lineNumber;
    };
}

#endif