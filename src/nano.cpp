/*
** EPITECH PROJECT, 2021
** nano
** File description:
** nano
*/

#include "gate.hpp"
#include "nano.hpp"

Nano::Nano(std::string const name, int input1, int input2, int output)
{
    _Input1 = new Gate(name + ":" + std::to_string(input1), Gate::INPUT, false);
    _Input2 = new Gate(name + ":" + std::to_string(input2), Gate::INPUT, false);
    _Output = new Gate(name + ":" + std::to_string(output), Gate::OUTPUT, false);
    this->_Value = 0;
}

Nano::Nano(std::string const name, int input1, int output)
{
    _Input1 = new Gate(name + ":" + std::to_string(input1), Gate::INPUT, false);
    _Input2 = NULL;
    _Output = new Gate(name + ":" + std::to_string(output), Gate::OUTPUT, false);
    this->_Value = 0;
}

Nano::~Nano()
{
}

bool Nano::getValue() const
{
    return (this->_Value);
}

void Nano::changeValue(bool value)
{
    this->_Value = value;
}
