#include "../include/operator.hpp"
#include "../include/globals.hpp"

namespace iwbs
{
    bool Operator::Assignment(Variable &variable, const Line &line)
    {
        if (!line.empty() && line.getNumberOfTokens() == 5)
        {
            const Token& typeToken = line[0];
            const Token& nameToken = line[1];
            const Token& token4    = line[3];
            const std::string& token4Value = token4.getValue();

            if (typeToken.getType() == Token::Type::VariableType && line[2].getValue() == "=")
            {
                const Variable::Type type = Globals::ResolveVariableType(typeToken.getValue());
                variable.setType(type);
                variable.setName(nameToken.getValue());
                variable.setValue(token4Value);
                return true;
            }
        }

        return false;
    }
}