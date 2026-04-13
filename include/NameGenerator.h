#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H 

#include <string>
#include <vector>

// A utility class for random name generation.
class NameGenerator
{
private:
    // 'inline static' allows to set the value in the header.
    inline static std::string m_namesFile = "data/names.txt";
    inline static std::string m_titlesFile = "data/titles.txt";
    
    static std::vector<std::string> m_names;
    static std::vector<std::string> m_titles;
    // Read txt file and populate vector.
    static void readFile(const std::string& filePath, std::vector<std::string>& vec);

public:
    static std::string generateName();
};

#endif