#include "../include/scope.hpp"

namespace iwbs
{
    Scope::Scope()
    {
    }

    Scope::~Scope()
    {
    }

    void Scope::pushScope(const Scope& scope)
    {
        scopes.push_back(scope);
    }

    void Scope::pushLine(const Line& line)
    {
        lines.push_back(line);
    }

    const std::vector<Scope>& Scope::getScopes() const
    {
        return scopes;
    }

    const std::vector<Line>& Scope::getLines() const
    {
        return lines;
    }

    std::vector<Scope>& Scope::getScopes()
    {
        return scopes;
    }

    std::vector<Line>& Scope::getLines()
    {
        return lines;
    }
}