/*
** EPITECH PROJECT, 2021
** gate
** File description:
** gate
*/

#include "gate.hpp"

Gate::Gate(std::string const Name = "", TGate Type = UNDEFINED, bool Value = false) :
    _Name(Name), _Type(Type), _Value(Value)
{
    _Link = NOTLINKED;
    _TValue = NOTDEFINED;
    _TWaiting = NOTHING;
}

Gate::~Gate()
{
}
