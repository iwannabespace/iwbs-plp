#include "../include/operator.hpp"
#include "../include/globals.hpp"
#include "../ext/exprtk.hpp"
#include <iostream>

namespace iwbs
{
    bool Operator::Assignment(Variable &variable, const Line &line)
    {
        if (!line.empty() && line.getNumberOfTokens() >= 5)
        {
            typedef exprtk::expression<double>   expression_t;
            typedef exprtk::parser<double>       parser_t;
            expression_t expression;
            parser_t parser;
            std::string sexpression;

            if (line[0].getType() == Token::Type::VariableType && line[2].getValue() == "=")
            {
                const Variable::Type type = Globals::ResolveVariableType(line[0].getValue());
                variable.setType(type);
                variable.setName(line[1].getValue());

                for (size_t i = 3; line[i].getType() != Token::Type::Semicolon; i++)
                    sexpression += line[i].getValue();

                switch (type)
                {
                    case Variable::Type::Integer:
                        if (parser.compile(sexpression, expression))
                        {
                            variable.setValue(std::to_string((int64_t)expression.value()));
                            return true;
                        }

                        else
                            return false;
                    case Variable::Type::Float:
                        if (parser.compile(sexpression, expression))
                        {
                            variable.setValue(std::to_string((double)expression.value()));
                            return true;
                        }

                        else
                            return false;
                        break;
                    default:
                        return false;
                }
            }
        }

        return false;
    }
}