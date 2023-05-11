#include <iostream>
#include "include/lexer.hpp"

int main()
{
    iwbs::Lexer lexer("main.iwbs");

    lexer.read();

    std::cout << lexer.getNumberOfLines() << std::endl;

    for (size_t i = 0; i < lexer.getNumberOfLines(); i++)
    {
        // for (size_t j = 0; j < lexer[i].getNumberOfTokens(); j++)
        // {
        //     std::cout << lexer[i][j].getValue() << " -> " << lexer[i][j].getType() << std::endl;
        // }

        std::cout << lexer[i] << " -> Line number: " << lexer[i].getLineNumber() << std::endl;
    }

    return 0;
}