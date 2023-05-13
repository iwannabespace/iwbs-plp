#ifndef PARSER_HPP
#define PARSER_HPP

#include "line.hpp"
#include "file_reader.hpp"
#include "variable_container.hpp"

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
            std::string getRange(size_t startIndex, uint8_t endChar, const std::string& str) const;
            std::vector<std::string> split(const std::string& str, const std::string& delim) const;
        private:
            std::vector<Line> lines;
            FileReader reader;
            VariableContainer container;
    };
}

#endif