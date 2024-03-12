/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "nano.hpp"
#include "gate.hpp"

#ifndef AND_HPP_
#define AND_HPP_

class And : public Nano
{
public:
    And();
    And(std::string const name, int input1, int input2, int output);
    ~And();
    void apply(Gate *Input1, Gate *Input2);
};

#endif
