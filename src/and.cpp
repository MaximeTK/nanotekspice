/*
** EPITECH PROJECT, 2021
** nano
** File description:
** nano
*/

#include "gate.hpp"
#include "nano.hpp"
#include "and.hpp"

And::And() : Nano("AND", 1, 2, 0)
{
}

And::And(std::string const name, int input1, int input2, int output) : Nano(name, input1, input2, output)
{
}

And::~And()
{
}

void And::apply(Gate *Input1, Gate *Input2)
{
    this->_Output[0].changeValue(0);
    this->_Output[0].changeTValue(Gate::DEFINED);
    if (Input1[0].getTValue() == Gate::DEFINED && Input2[0].getTValue() == Gate::DEFINED) {
        if (Input1[0].getValue() == 1 && Input2[0].getValue() == 1)
            this->_Output[0].changeValue(1);
        this->_Output[0].changeTValue(Gate::DEFINED);
    }
    if (Input1[0].getTValue() == Gate::NOTDEFINED && Input2[0].getTValue() != Gate::NOTDEFINED) {
        this->_Output[0].changeTValue(Gate::DEFINED);
        if (Input2[0].getValue() == 1) this->_Output[0].changeTValue(Gate::NOTDEFINED);
    }
    if (Input1[0].getTValue() != Gate::NOTDEFINED && Input2[0].getTValue() == Gate::NOTDEFINED) {
        this->_Output[0].changeTValue(Gate::DEFINED);
        if (Input1[0].getValue() == 1) this->_Output[0].changeTValue(Gate::NOTDEFINED);
    }
    if (Input1[0].getTValue() == Gate::NOTDEFINED && Input2[0].getTValue() == Gate::NOTDEFINED)
        this->_Output[0].changeTValue(Gate::NOTDEFINED);
}
