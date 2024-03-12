/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "nano.hpp"
#include "gate.hpp"

#ifndef XOR_HPP_
#define XOR_HPP_

class Xor : public Nano
{
public:
    Xor();
    Xor(std::string const name, int input1, int input2, int output);
    ~Xor();
    void apply(Gate *Input1, Gate *Input2);
};

#endif
