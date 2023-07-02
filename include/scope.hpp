#ifndef SCOPE_HPP
#define SCOPE_HPP

#include "line.hpp"
#include "variable_container.hpp"
#include <vector>

namespace iwbs
{
    class Scope
    {
        public:
            Scope();
            ~Scope();
            void pushScope(const Scope& scope);
            void pushLine(const Line& line);
            const std::vector<Scope>& getScopes() const;
            const std::vector<Line>& getLines() const;
            std::vector<Scope>& getScopes();
            std::vector<Line>& getLines();
        private:
            std::vector<Scope> scopes;
            std::vector<Line> lines;
            VariableContainer variables;
    };
}

#endif