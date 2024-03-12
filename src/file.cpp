/*
** EPITECH PROJECT, 2021
** file
** File description:
** file
*/

#include "system.hpp"

void System::AddLine(std::string const line)
{
    this->_File.push_back(line);
    this->_NbrLineFile++;
}

void System::take_file(char const *str)
{
    std::string line;
    std::ifstream file (str);

    if (file.is_open()) {
        while (getline(file, line)) {
            AddLine(line + '\n');
        }
        file.close();
    }
    else std::cerr << "Unable to open file";
}
