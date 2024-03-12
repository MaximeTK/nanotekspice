/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "nano.hpp"
#include "gate.hpp"

#ifndef NAND_HPP_
#define NAND_HPP_

class Nand : public Nano
{
public:
    Nand();
    Nand(std::string const name, int input1, int input2, int output);
    ~Nand();
    void apply(Gate *Input1, Gate *Input2);
};

#endif
