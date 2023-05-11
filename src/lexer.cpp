#include "../include/lexer.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

namespace iwbs
{
    Lexer::Lexer()
        : filename("")
    {
    }

    Lexer::Lexer(const std::string& filename)
        : filename(filename)
    {
        if (!std::filesystem::exists(filename))
        {    
            this->filename.clear();
            throw "File couldn't be found!";
        }
    }

    Lexer::~Lexer()
    {
    }

    void Lexer::read()
    {
        if (!filename.empty())
        {
            std::fstream file;
            std::string lineStr;
            Line line;
            size_t number = 1;

            file.open(filename, std::ios::in);
            
            while (std::getline(file, lineStr))
            {
                std::string lineToken;
                int numberOfQuotes = 0;

                for (size_t i = 0; i < lineStr.length(); i++)
                {
                    lineToken += lineStr[i];

                    if (lineStr[i] == '\"')
                        numberOfQuotes++;

                    if (numberOfQuotes == 2)
                    {
                        line.pushToken(Token(lineToken, Token::Type::StringValue));
                        lineToken.clear();
                        numberOfQuotes = 0;
                    }

                    if (lineStr[i] == ' ' && !numberOfQuotes)
                    {
                        if (lineToken.length() != 1) // This is checked because, if there is an empty char after a semicolon this code block would push an empty token to the line  
                            line.pushToken(Token(lineToken.substr(0, lineToken.length() - 1), Token::Type::Unknown));
                        
                        lineToken.clear();
                    }

                    if (lineStr[i] == ';' && !numberOfQuotes)
                    {
                        if (lineToken.length() != 1)
                            line.pushToken(Token(lineToken.substr(0, lineToken.length() - 1), Token::Type::Unknown));

                        line.pushToken(Token(";", Token::Type::Semicolon));
                        lineToken.clear();
                    }
                }

                line.setLineNumber(number++);
                lines.push_back(line);
                line.clear();
            }

            file.close();
        }
    }

    void Lexer::setFile(const std::string& filename)
    {
        if (!std::filesystem::exists(filename))
            throw "File couldn't be found!";

        this->filename = filename;
    }

    const std::string& Lexer::getFile() const
    {
        return filename;
    }

    size_t Lexer::getNumberOfLines() const
    {
        return lines.size();
    }

    void Lexer::clear()
    {
        lines.clear();
        filename.clear();
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
            if (line.contains(Token("=", Token::Type::Unknown)))

            for (Token& token : line) 
            {
                if (token.getType() == Token::Type::Unknown)
                {

                }
            }
        }
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

/*

std::istringstream stream(lineStr);
                std::string lineToken;
                std::string strValueHolder;
                int numberOfQuotes = 0;

                while (stream >> lineToken)
                {
                    if (lineToken.find("\"") != std::string::npos)
                        numberOfQuotes++;
                    
                    if (numberOfQuotes == 0)
                    {
                        auto semicolonTokens = split(lineToken, ";");

                        if (!semicolonTokens.empty())
                        {
                            for (const std::string& semicolonToken : semicolonTokens)
                            {
                                if (!semicolonToken.empty())
                                {
                                    line.pushToken(Token(semicolonToken, Token::Type::Unknown));
                                    line.pushToken(Token(";", Token::Type::Semicolon));
                                }

                                else
                                    line.pushToken(Token(";", Token::Type::Semicolon));
                            }

                            continue;
                        }
                        
                        else
                            line.pushToken(Token(lineToken, Token::Type::Unknown));
                    }

                    else if (numberOfQuotes == 1)
                        strValueHolder += lineToken;

                    else if (numberOfQuotes == 2)
                    {
                        strValueHolder += lineToken;
                        numberOfQuotes = 0;
                        line.pushToken(Token(strValueHolder, Token::Type::StringValue));
                    }
                }
                
                line.setLineNumber(number++);
                lines.push_back(line);
                line.clear();

*/