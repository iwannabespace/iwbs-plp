#include "../include/lexer.hpp"
#include "../include/globals.hpp"
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
        size_t lineNumber = 1;
        
        for (const std::string& lineStr : allLines)
        {
            Line line = extractTokens(lineStr);
            line.setLineNumber(lineNumber++);
            lines.push_back(line);
        }
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

    Line Lexer::extractTokens(const std::string& str) const
    {
        iwbs::Line line;

        for (size_t i = 0; i < str.length(); i++)
        {
            int8_t current = str[i];

            switch (current)
            {
                case '(':
                    line.pushToken({ "(", Token::Type::OParan });
                    continue;
                case ')':
                    line.pushToken({ ")", Token::Type::CParan });
                    continue;
                case '{':
                    line.pushToken({ "{", Token::Type::OCurly });
                    continue;
                case '}':
                    line.pushToken({ "}", Token::Type::CCurly });
                    continue;
                case '[':
                    line.pushToken({ "[", Token::Type::OBracket });
                    continue;
                case ']':
                    line.pushToken({ "]", Token::Type::CBracket });
                    continue;
                case ';':
                    line.pushToken({ ";", Token::Type::Semicolon });
                    continue;
                case '"':
                {                
                    std::string value = Globals::GetRange(i, '"', str);
                    i += (value.length() - 1);
                    line.pushToken({ value, Token::Type::SConstant });
                    continue;
                }
                case '=':
                case '+':
                case '-':
                case '*':
                case '/':
                case '.':
                case ',':
                    line.pushToken({ std::string{current}, Token::Type::Operator });
                    continue;
            }

            if (std::isalnum(current))
            {
                std::string value{current};

                for (++i; i < str.length() && (std::isalnum(str[i]) || str[i] == '.'); i++)
                {
                    current = str[i];
                    value += current;
                }

                Token::Type type = Globals::ResolveTokenType(value);

                if (!line.empty() && (type == Token::Type::IConstant || type == Token::Type::FConstant))
                {  
                    Token& prev = line[line.getNumberOfTokens() - 1];
                    const std::string& prevValue = prev.getValue();

                    if (prevValue == "-" || prevValue == "+")
                    {    
                        prev.setValue(prevValue + value);
                        prev.setType(type);
                        i--;
                        continue;
                    }
                }
                
                line.pushToken({ value, type});
                
                i--;
            }
        }

        return line;
    }
}