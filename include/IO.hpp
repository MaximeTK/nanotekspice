/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "nano.hpp"
#include "gate.hpp"

#ifndef IO_HPP_
#define IO_HPP_

class IO : public Nano
{
public:
    IO();
    IO(std::string const name, int input1, int output);
    ~IO();
    void apply(Gate *Input1);
};

#endif
