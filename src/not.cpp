/*
** EPITECH PROJECT, 2021
** nano
** File description:
** nano
*/

#include "gate.hpp"
#include "nano.hpp"
#include "not.hpp"

Not::Not() : Nano("NOT", 1, 1)
{
}

Not::Not(std::string const name, int input1, int output) : Nano(name, input1, output)
{
}

Not::~Not()
{
}

void Not::apply(Gate *Input1)
{
    if (Input1[0].getTValue() == Gate::NOTDEFINED)
        this->_Output[0].changeTValue(Gate::NOTDEFINED);
    else
        this->_Output[0].changeTValue(Gate::DEFINED);
    if (Input1[0].getValue() == 1)
        this->_Output[0].changeValue(0);
    if (Input1[0].getValue() == 0)
        this->_Output[0].changeValue(1);
}
