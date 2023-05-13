#include "../include/file_reader.hpp"
#include <fstream>

namespace iwbs
{
    FileReader::FileReader()
    {
    }

    FileReader::FileReader(const std::string& filename)
        : filename(filename)
    {
    }

    FileReader::~FileReader()
    {
    }

    void FileReader::read()
    {
        if (!filename.empty() && std::filesystem::exists(filename))
        {
            std::fstream file;
            std::string line;

            file.open(filename, std::ios::in);
            
            while (std::getline(file, line))
                lines.push_back(line);
            
            file.close();
        }
        
        else 
            throw std::string("File '" + filename + "' couldn't be found!");
    }

    void FileReader::setFile(const std::string& filename)
    {
        this->filename = filename;
    }

    const std::string& FileReader::getFile() const
    {
        return filename;
    }   

    std::vector<std::string> FileReader::data()
    {
        return lines;
    }

    const std::vector<std::string>& FileReader::data() const
    {
        return lines;
    }
}