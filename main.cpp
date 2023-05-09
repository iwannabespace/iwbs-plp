#include <iostream>
#include "include/lexer.hpp"

int main()
{
    iwbs::Lexer lexer("main.iwbs");

    lexer.read();

    for (size_t i = 0; i < lexer.getNumberOfLines(); i++)
    {
        for (size_t j = 0; j < lexer[i].getNumberOfTokens(); j++)
        {
            std::cout << lexer[i][j].getValue() << " -> " << lexer[i][j].getType() << std::endl;
        }
    }

    return 0;
}