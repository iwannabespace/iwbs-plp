#ifndef PARSER_HPP
#define PARSER_HPP

#include "line.hpp"
#include "variable_container.hpp"

namespace iwbs
{
    class Lexer
    {
        public:
            Lexer();
            Lexer(const std::string& filename);
            ~Lexer();
            void read();
            void setFile(const std::string& filename);
            const std::string& getFile() const;
            size_t getNumberOfLines() const;
            void clear();
            const Line& operator[](size_t index) const;
            Line& operator[](size_t index);
        private:    
            void analyze();
            std::vector<std::string> split(const std::string& str, const std::string& delim) const;
        private:
            std::string filename;
            std::vector<Line> lines;
            VariableContainer container;
    };
}

#endif