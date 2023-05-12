#include "../include/error.hpp"

namespace iwbs
{
    Error::Error()
        : lineNumber(0)
    {
        message = "None";
    }

    Error::Error(const std::string& message, size_t lineNumber)
        : message(message), lineNumber(lineNumber)
    {
    }

    Error::~Error()
    {
    }

    void Error::setMessage(const std::string& message)
    {
        if (message.empty())
            this->message = "None";
        
        else
            this->message = message;
    }

    void Error::setLineNumber(size_t lineNumber)
    {
        this->lineNumber = lineNumber;
    }

    const std::string& Error::getMessage() const
    {
        return message;
    }

    size_t Error::getLineNumber() const
    {
        return lineNumber;
    }
}