#include <iostream>
#include "include/parser.hpp"
#include "include/globals.hpp"
#include "include/operator.hpp"

int main()
{
    iwbs::Parser parser(iwbs::FileReader("main.iwbs"));

    parser.parse();

    auto variables = parser.getVariables();


    for (size_t i = 0; i < variables.size(); i++)
    {
        if (variables[i].getType() == iwbs::Variable::Type::Integer)
        {
            auto result = iwbs::Globals::ConvertToInteger(variables[i].getValue());

            std::cout << result.value_or(-1) << std::endl;
        }
    }

    return 0;
}

