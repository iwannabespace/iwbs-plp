#ifndef LEXER_HPP
#define LEXER_HPP

#include "scope.hpp"
#include "file_reader.hpp"

namespace iwbs
{
    class Lexer
    {
        public:
            Lexer(const FileReader& reader);
            ~Lexer();
            void tokenize();
            void clear();
            const std::string& filename() const;
            size_t getNumberOfScopes() const;
            const Scope& operator[](size_t index) const;
            Scope& operator[](size_t index);
        private:    
            Line extractTokens(const std::string& str) const;
        private:
            std::vector<Scope> scopes;
            FileReader reader;
    };
}

#endif