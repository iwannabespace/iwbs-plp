#include <iostream>
#include "include/parser.hpp"

int main()
{
    iwbs::Parser parser(iwbs::FileReader("main.iwbs"));

    parser.parse();

    auto variables = parser.getVariables();

    for (size_t i = 0; i < variables.size(); i++)
    {
        std::cout << "Name: " << variables[i].getName() << std::endl;
        std::cout << "Value: " << variables[i].getValue() << std::endl;
    }

    // iwbs::Lexer lexer(iwbs::FileReader("main.iwbs"));

    // lexer.tokenize();

    // for (size_t i = 0; i < lexer.getNumberOfLines(); i++)
    // {
    //     std::cout << "Line number: " << lexer[i].getLineNumber() << std::endl;
    //     std::cout << "Line error: " << lexer[i].getError().getMessage() << std::endl;

    //     for (size_t j = 0; j < lexer[i].getNumberOfTokens(); j++)
    //         std::cout << "\t" << lexer[i][j].getValue() << " -> " << lexer[i][j].getType() << std::endl;

    //     //std::cout << lexer[i] << " -> Line number: " << lexer[i].getLineNumber() << std::endl;
    // }

    return 0;
}

