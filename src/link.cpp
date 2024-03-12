/*
** EPITECH PROJECT, 2021
** nano
** File description:
** nano
*/

#include "link.hpp"

Link::Link(std::string const Name = "", std::string const Link = "", Gate::TGate type = Gate::UNDEFINED) : _Name(Name + ":1"), _Link(Link)
{
    _Gate = new Gate(Name + ":1", type, false);
    _Displayable = 1;
}

Link::~Link()
{
}
