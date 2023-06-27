#ifndef LEXER_HPP
#define LEXER_HPP

#include "line.hpp"
#include "file_reader.hpp"

namespace iwbs
{
    class Lexer
    {
        public:
            Lexer(const FileReader& reader);
            ~Lexer();
            void tokenize();
            const std::string& filename() const;
            size_t getNumberOfLines() const;
            void clear();
            const Line& operator[](size_t index) const;
            Line& operator[](size_t index);
        private:    
            void analyze();
            Line extractTokens(const std::string& str) const;
        private:
            std::vector<Line> lines;
            FileReader reader;
    };
}

#endif