/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "nano.hpp"
#include "gate.hpp"

#ifndef OR_HPP_
#define OR_HPP_

class Or : public Nano
{
public:
    Or();
    Or(std::string const name, int input1, int input2, int output);
    ~Or();
    void apply(Gate *Input1, Gate *Input2);
};

#endif
