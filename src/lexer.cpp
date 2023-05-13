#include "../include/lexer.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

namespace iwbs
{
    Lexer::Lexer(const FileReader& reader)
        : reader(reader)
    {
    }

    Lexer::~Lexer()
    {
    }

    void Lexer::tokenize()
    {
        try {
            reader.read();
        } catch (const std::string& exception) {
            std::cout << exception << std::endl;
            return;
        }

        auto allLines = reader.data();
        size_t number = 1;
        
        for (const std::string& lineStr : allLines)
        {
            Line line = extractTokens(lineStr);
            line.setLineNumber(number++);
            lines.push_back(line);
        }

        //analyze();
    }

    const std::string& Lexer::filename() const
    {
        return reader.getFile();
    }

    size_t Lexer::getNumberOfLines() const
    {
        return lines.size();
    }

    void Lexer::clear()
    {
        lines.clear();
    }

    const Line& Lexer::operator[](size_t index) const
    {
        if (index < 0 || index >= lines.size())
            throw "Index out of bounds for Lexer::lines container";

        return lines[index];
    }

    Line& Lexer::operator[](size_t index)
    {
        if (index < 0 || index >= lines.size())
            throw "Index out of bounds for Lexer::lines container";

        return lines[index];
    }

    void Lexer::analyze()
    {
        for (Line& line : lines)
        {
            int32_t numberOfSemicolons = line.count(Token(";", Token::Type::Semicolon));
            size_t lineNumber = line.getLineNumber();

            if (numberOfSemicolons != 1)
            {   
                line.setError(Error(numberOfSemicolons < 1 ? "Missing semicolon error" : "Multiple semicolons error", lineNumber));
                continue;
            }
            
            else
            {
                if (line.contains("="))
                {
                    if (line.getNumberOfTokens() < 5)
                    {
                        
                    }

                    if (line.count("=") > 1)
                    {    
                        line.setError(Error("Multiple assignment operator error", lineNumber));
                        continue;
                    }

                    if (line[2] != Token("="))
                    {
                        line.setError(Error("Assignment operator is not in place error", lineNumber));
                        continue;
                    }

                    Variable::Type type = Variable::Resolve(line[0].getValue());
                    if (type != Variable::Type::Unknown)
                        line[0].setType(Token::Type::Type);
                    
                    else
                    {
                        line.setError(Error("Unknown token error", lineNumber));
                        continue;
                    }

                    bool isValidName = Variable::IsValidVariableName(line[1].getValue());
                    if (isValidName)
                        line[1].setType(Token::Type::Identifier);
                    
                    else
                    {
                        line.setError(Error("Incorrect variable naming error", lineNumber));
                        continue;
                    }

                }
            }
        }
    }

    Line Lexer::extractTokens(const std::string& str) const
    {
        iwbs::Line line;

        for (size_t i = 0; i < str.length(); i++)
        {
            char current_char = str[i];

            if (std::isalnum(current_char))
            {
                std::string value{current_char};

                for (++i; std::isalnum(str[i]) && i < str.length(); i++)
                {
                    current_char = str[i];
                    value += current_char;
                }
                
                i--;
                line.pushToken(iwbs::Token(value, iwbs::Token::Type::Constant));
            }

            else if (current_char == '"')
            {
                std::string value = getRange(i, '"', str);
                i += (value.length() - 1);
                line.pushToken(iwbs::Token(value, iwbs::Token::Type::Constant));
            }

            else if (current_char == ';')
                line.pushToken(iwbs::Token(";", iwbs::Token::Type::Semicolon));

            else if (!std::isspace(current_char))
            {
                std::string value{current_char};

                for (++i; !std::isspace(str[i]) && str[i] != ';' && i < str.length(); i++)
                {
                    current_char = str[i];
                    value += current_char;
                }

                i--;
                line.pushToken(iwbs::Token(value, iwbs::Token::Type::Unknown));
            }
        }

        return line;
    }

    std::string Lexer::getRange(size_t startIndex, uint8_t endChar, const std::string& str) const
    {
        return str.substr(startIndex, str.find(endChar, startIndex + 1) - (startIndex - 1));
    }

    std::vector<std::string> Lexer::split(const std::string& str, const std::string& delim) const
    {
        std::vector<std::string> result;
        size_t start = 0;
        size_t end = 0;

        if (str.find(delim) == std::string::npos)
            return std::vector<std::string>{};

        while ((end = str.find(delim, start)) != std::string::npos)
        {
            result.push_back(str.substr(start, end - start));
            start = end + delim.length();
        }

        std::string lastToken = str.substr(start);

        if (!lastToken.empty())
            result.push_back(lastToken);

        return result;
    }
}