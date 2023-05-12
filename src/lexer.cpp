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

    Lexer::Lexer(const std::string &filename)
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
            std::string lineToken;
            int numberOfQuotes = 0;

            while (std::getline(file, lineStr))
            {
                line.setLineNumber(number++);

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
                            line.pushToken(Token(lineToken.substr(0, lineToken.length() - 1)));

                        lineToken.clear();
                    }

                    if (lineStr[i] == ';' && !numberOfQuotes)
                    {
                        if (lineToken.length() != 1)
                            line.pushToken(Token(lineToken.substr(0, lineToken.length() - 1)));

                        line.pushToken(Token(";", Token::Type::Semicolon));
                        lineToken.clear();
                        lines.push_back(line);
                        line.clear();
                    }
                }

                //     lines.push_back(line);
                //    line.clear();
            }

            file.close();
            analyze();
        }
    }

    void Lexer::setFile(const std::string &filename)
    {
        if (!std::filesystem::exists(filename))
            throw "File couldn't be found!";

        this->filename = filename;
    }

    const std::string &Lexer::getFile() const
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

    const Line &Lexer::operator[](size_t index) const
    {
        if (index < 0 || index >= lines.size())
            throw "Index out of bounds for Lexer::lines container";

        return lines[index];
    }

    Line &Lexer::operator[](size_t index)
    {
        if (index < 0 || index >= lines.size())
            throw "Index out of bounds for Lexer::lines container";

        return lines[index];
    }

    void Lexer::analyze()
    {
        for (Line &line : lines)
        {
            int32_t numberOfSemicolons = line.count(Token(";", Token::Type::Semicolon));
            size_t lineNumber = line.getLineNumber();

            if (numberOfSemicolons < 1)
            {
                line.setError(Error("Missing semicolon error", lineNumber));
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
                        line[0].setType(Token::Type::VariableType);

                    else
                    {
                        line.setError(Error("Unknown token error", lineNumber));
                        continue;
                    }

                    bool isValidName = Variable::IsValidVariableName(line[1].getValue());
                    if (isValidName)
                        line[1].setType(Token::Type::VariableName);

                    else
                    {
                        line.setError(Error("Incorrect variable naming error", lineNumber));
                        continue;
                    }
                }
            }
        }
    }

    std::vector<std::string> Lexer::split(const std::string &str, const std::string &delim) const
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