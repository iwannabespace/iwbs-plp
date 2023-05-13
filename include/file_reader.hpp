#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <string>
#include <vector>

namespace iwbs
{
    class FileReader
    {
        public:
            FileReader();
            FileReader(const std::string& filename);
            ~FileReader();
            void read();
            void setFile(const std::string& filename);
            const std::string& getFile() const;
            std::vector<std::string> data();
            const std::vector<std::string>& data() const;
        private:
            std::string filename;
            std::vector<std::string> lines;
    };
}

#endif