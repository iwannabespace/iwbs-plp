#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"
#include "variable_container.hpp"

namespace iwbs
{
    class Parser
    {
        public:
            Parser(const FileReader& reader);
            ~Parser();
            void parse();
            const VariableContainer& getVariables() const;
        private:
            void setVariables();
        private:
            Lexer lexer;
            VariableContainer variableContainer;
    };
}

#endif