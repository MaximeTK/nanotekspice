/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "nano.hpp"
#include "gate.hpp"

#ifndef NOR_HPP_
#define NOR_HPP_

class Nor : public Nano
{
public:
    Nor();
    Nor(std::string const name, int input1, int input2, int output);
    ~Nor();
    void apply(Gate *Input1, Gate *Input2);
};

#endif
