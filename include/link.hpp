/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <ostream>
#include <iostream>
#include <string>
#include "gate.hpp"

#ifndef LINK_HPP_
#define LINK_HPP_

class Link
{
public:
    Link(std::string const Name, std::string const link, Gate::TGate type);
    ~Link();
    std::string getName() const { return (_Name); }
    std::string getLink() const { return (_Link); }
    Gate *getGate() const { return (_Gate); }
    void changeDisplayStatus(bool value) { _Displayable = value; }
    void changeGate(Gate *const Gate) { _Gate = Gate; }
    void changeLink(std::string const link) { _Link = link; }
    void changeName(std::string const name) { _Name = name; }
    bool getDisplayStatus() const { return (_Displayable); }
private:
    std::string _Name;
    std::string _Link;
    bool _Displayable;
    Gate *_Gate;
};
#endif
