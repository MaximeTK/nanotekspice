/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "nano.hpp"
#include "gate.hpp"

#ifndef NOT_HPP_
#define NOT_HPP_

class Not : public Nano
{
public:
    Not();
    Not(std::string const name, int input1, int output);
    ~Not();
    void apply(Gate *Input1);
};

#endif
