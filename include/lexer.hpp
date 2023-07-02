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
            void clear();
            const std::string& filename() const;
            size_t getNumberOfLines() const;
            const Line& operator[](size_t index) const;
            Line& operator[](size_t index);
        private:    
            Line extractTokens(const std::string& str) const;
        private:
            std::vector<Line> lines;
            FileReader reader;
    };
}

#endif