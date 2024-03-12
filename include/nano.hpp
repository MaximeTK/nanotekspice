/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include "gate.hpp"

#ifndef NANO_H_
#define NANO_H_

class Nano
{
public:
    Nano(std::string const name, int input1, int input2, int output);
    Nano(std::string const name, int input1, int output);
    ~Nano();
    bool getValue() const;
    void changeValue(bool value);
    Gate *getInput1() const { return(this->_Input1); }
    Gate *getInput2() const { return(this->_Input2); }
    Gate *getOutput() const { return(this->_Output); }
    void changeInput1(Gate *const input1) { _Input1 = input1; _Input1->changeLink(Gate::LINKED); }
    void changeInput2(Gate *const input2) { _Input2 = input2; _Input2->changeLink(Gate::LINKED); }
    void changeOutput1(Gate *const output1) { _Output = output1; _Output->changeLink(Gate::LINKED); }
protected:
    Gate *_Input1;
    Gate *_Input2;
    Gate *_Output;
    bool _Value;
};

#endif
