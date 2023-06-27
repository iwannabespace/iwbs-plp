#include <iostream>
#include <vector>

enum class TokenType
{
    NAME,
    OPEN_PARAN,
    CLOSE_PARAN,
    OPEN_CURLY,
    CLOSE_CURLY,
    OPERATOR,
    SEMICOLON,
    STRING,
};

struct Token
{
    std::string value;
    TokenType type;
};

std::vector<std::vector<Token>> getTokens(const std::vector<std::string>& lines)
{
    std::vector<std::vector<Token>> result;

    for (const std::string& line : lines)
    {   
        std::vector<Token> data;

        for (size_t i = 0; i < line.length(); i++)
        {
            int8_t current = line[i];

            switch (current)
            {
                case '(':
                    data.push_back({ "(", TokenType::OPEN_PARAN });
                    continue;
                    break;
                case ')':
                    data.push_back({ ")", TokenType::CLOSE_PARAN });
                    continue;
                    break;
                case '{':
                    data.push_back({ "{", TokenType::OPEN_CURLY });
                    continue;
                    break;
                case '}':
                    data.push_back({ "}", TokenType::CLOSE_CURLY });
                    continue;
                    break;
                case ';':
                    data.push_back({ ";", TokenType::SEMICOLON });
                    continue;
                    break;
                case '"':
                {                
                    std::string value = line.substr(i, line.find('"', i + 1) - (i - 1));
                    i += (value.length() - 1);
                    data.push_back({ value, TokenType::STRING });
                    continue;
                    break;
                }
                case '=':
                case '+':
                case '-':
                case '*':
                case '/':
                    data.push_back({ std::string{current}, TokenType::OPERATOR });
                    continue;
                    break;
            }

            if (std::isalnum(current))
            {
                std::string value{current};

                for (++i; std::isalnum(line[i]) && i < line.length(); i++)
                {
                    current = line[i];
                    value += current;
                }
                
                i--;
                data.push_back({ value, TokenType::NAME });
            }
        }

        result.push_back(data);
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, TokenType type)
{
    switch (type)
    {
        case TokenType::NAME:
            os << "NAME"; 
            break;
        case TokenType::OPEN_PARAN:
            os << "OPEN PARAN"; 
            break;
        case TokenType::CLOSE_PARAN:
            os << "CLOSE PARAN"; 
            break;
        case TokenType::OPEN_CURLY:
            os << "OPEN CURLY"; 
            break;
        case TokenType::CLOSE_CURLY:
            os << "CLOSE CURLY"; 
            break;
        case TokenType::OPERATOR:
            os << "OPERATOR"; 
            break;
        case TokenType::SEMICOLON:
            os << "SEMICOLON"; 
            break;
        case TokenType::STRING:
            os << "STRING"; 
            break;
    }

    return os;
}

int main()
{
    auto result = getTokens(std::vector<std::string>{
        "string1 testDegisken = \"merhaba emin \";"
    });

    for (const auto& line : result)
    {
        for (const auto& token : line)
        {
            std::cout << token.value << " -> " << token.type << std::endl;
        }
    }

    return 0;
}