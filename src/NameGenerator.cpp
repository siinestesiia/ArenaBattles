#include "NameGenerator.h"

#include <iostream>
#include <fstream>
#include <random>

// Static members have to be initialized outside the class
std::vector<std::string> NameGenerator::m_names;
std::vector<std::string> NameGenerator::m_titles;

void NameGenerator::readFile(const std::string& filePath, std::vector<std::string>& vec)
{
    // Only read if vectors are empty (not containing names/titles).
    if (vec.empty())
    {
        std::ifstream txtFile(filePath);
        if (!txtFile.is_open())
        {
            std::cerr << "Error: " << filePath << " file not found..." << std::endl;
            return;
        }
        std::string line;
        while (std::getline(txtFile, line))
        {
            // Ignore empty lines or comments with #
            if (line.empty() || line[0] == '#') continue;
            vec.push_back(line);
        }
        txtFile.close();
    }
}

std::string NameGenerator::generateName()
{
    readFile(m_namesFile, m_names);
    readFile(m_titlesFile, m_titles);

    // Safety check.
    if (m_names.empty() || m_titles.empty()) return "Vectors containers are empty...";

    // Random logic.
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> nameDist(0, m_names.size() - 1);
    std::uniform_int_distribution<> titleDist(0, m_titles.size() - 1);
    
    return m_names[nameDist(gen)] + " " + m_titles[titleDist(gen)];
}