#include "../include/parser.hpp"
#include "../include/globals.hpp"
#include "../include/operator.hpp"
#include <iostream>

namespace iwbs
{
    Parser::Parser(const FileReader& reader)
        : lexer(reader)
    {
    }

    Parser::~Parser()
    {
    }

    void iwbs::Parser::parse()
    {
        lexer.tokenize();
        setVariables();

        // size_t lineCount = lexer.getNumberOfLines();
        // for (size_t i = 0; i < lineCount; i++)
        // {
        //     Line& line = lexer[i];

        //     if (!line.empty())
        //     {

        //     }
        // }
    }

    void iwbs::Parser::setVariables()
    {
        size_t lineCount = lexer.getNumberOfLines();

        for (size_t i = 0; i < lineCount; i++)
        {
            Line& line = lexer[i];
            Variable variable;

            bool result = Operator::Assignment(variable, line);

            if (result)
            {
                std::cout << "Variable is added!" << std::endl;
                variableContainer.pushVariable(variable);
            }
        }
    }

    const VariableContainer &Parser::getVariables() const
    {
        return variableContainer;
    }
}