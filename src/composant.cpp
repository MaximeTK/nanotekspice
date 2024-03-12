/*
** EPITECH PROJECT, 2021
** nano
** File description:
** nano
*/

#include "and.hpp"
#include "nand.hpp"
#include "or.hpp"
#include "xor.hpp"
#include "nor.hpp"
#include "composant.hpp"
#include "IO.hpp"

Composant::Composant(std::string const name) : _Name(name), _Type(UNDEFINED)
{
    _NbrAnd = 0;
    _NbrNand = 0;
    _NbrOr = 0;
    _NbrXor = 0;
    _NbrNot = 0;
    _NbrNor = 0;
    _NbrIO = 0;
}

Composant::~Composant()
{
}

void Composant::Reload()
{
    int block = 1;

    for (int x = 0; block != 0; x++){
        block = 0;
        if (x < _NbrAnd) {
            _And[x].apply(_And[x].getInput1(), _And[x].getInput2());
            block = 1;
        }
        if (x < _NbrNand) {
            _Nand[x].apply(_Nand[x].getInput1(), _Nand[x].getInput2());
            block = 1;
        }
        if (x < _NbrOr) {
            _Or[x].apply(_Or[x].getInput1(), _Or[x].getInput2());
            block = 1;
        }
        if (x < _NbrXor) {
            _Xor[x].apply(_Xor[x].getInput1(), _Xor[x].getInput2());
            block = 1;
        }
        if (x < _NbrNot) {
            _Not[x].apply(_Not[x].getInput1());
            block = 1;
        }
        if (x < _NbrNor) {
            _Nor[x].apply(_Nor[x].getInput1(), _Nor[x].getInput2());
            block = 1;
        }
        if (x < _NbrIO) {
            _IO[x].apply(_IO[x].getInput1());
            block = 1;
        }
    }
}

void Composant::DumpSelector(Gate::TValue tvalue, bool Value, int nbr) const
{
    if (tvalue != Gate::NOTDEFINED) std::cout << "         PIN #" << nbr << ": "<< Value << std::endl;
    else std::cout << "         PIN #" << nbr << ": U" << std::endl;
}

void Composant::DumpLinker(Gate::TLink link, Gate::TValue tvalue, bool Value, int nbr) const
{
    if (link != Gate::NOTLINKED) DumpSelector(tvalue, Value, nbr);
    else std::cout << "         PIN #" << nbr << ": NULL" << std::endl;
}

int Composant::DumpIgnored(int nbr) const
{
    nbr++;
    if (nbr == 7 || nbr == 14) {
        std::cout << "         PIN #" << nbr << ": IGN" << std::endl;
        nbr++;
    }
    return (nbr);
}

void Composant::LaunchDumpAnd() const
{
    int nbr = 1;

    for (int x = 0; x < _NbrAnd; x++) {
        DumpLinker(_And[x].getInput1()->getLink(), _And[x].getInput1()->getTValue(), _And[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_And[x].getInput2()->getLink(), _And[x].getInput2()->getTValue(), _And[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_And[x].getOutput()->getLink(), _And[x].getOutput()->getTValue(), _And[x].getOutput()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
    }
}

void Composant::LaunchDumpNand() const
{
    int nbr = 1;

    for (int x = 0; x < _NbrNand; x++) {
        DumpLinker(_Nand[x].getInput1()->getLink(), _Nand[x].getInput1()->getTValue(), _Nand[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Nand[x].getInput2()->getLink(), _Nand[x].getInput2()->getTValue(), _Nand[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Nand[x].getOutput()->getLink(), _Nand[x].getOutput()->getTValue(), _Nand[x].getOutput()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
    }
}

void Composant::LaunchDumpOr() const
{
    int nbr = 1;

    for (int x = 0; x < _NbrOr; x++) {
        DumpLinker(_Or[x].getInput1()->getLink(), _Or[x].getInput1()->getTValue(), _Or[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Or[x].getInput2()->getLink(), _Or[x].getInput2()->getTValue(), _Or[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Or[x].getOutput()->getLink(), _Or[x].getOutput()->getTValue(), _Or[x].getOutput()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
    }
}

void Composant::LaunchDumpNor() const
{
    int nbr = 1;

    for (int x = 0; x < _NbrNor; x++) {
        DumpLinker(_Nor[x].getInput1()->getLink(), _Nor[x].getInput1()->getTValue(), _Nor[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Nor[x].getInput2()->getLink(), _Nor[x].getInput2()->getTValue(), _Nor[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Nor[x].getOutput()->getLink(), _Nor[x].getOutput()->getTValue(), _Nor[x].getOutput()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
    }
}

void Composant::LaunchDumpXor() const
{
    int nbr = 1;

    for (int x = 0; x < _NbrXor; x++) {
        DumpLinker(_Xor[x].getInput1()->getLink(), _Xor[x].getInput1()->getTValue(), _Xor[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Xor[x].getInput2()->getLink(), _Xor[x].getInput2()->getTValue(), _Xor[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Xor[x].getOutput()->getLink(), _Xor[x].getOutput()->getTValue(), _Xor[x].getOutput()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
    }
}

void Composant::LaunchDumpNot() const
{
    int nbr = 1;


    for (int x = 0; x < _NbrNot; x++) {
        DumpLinker(_Not[x].getInput1()->getLink(), _Not[x].getInput1()->getTValue(), _Not[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_Not[x].getOutput()->getLink(), _Not[x].getOutput()->getTValue(), _Not[x].getOutput()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
    }
}

void Composant::LaunchDumpIO() const
{
    int nbr = 1;

    for (int x = 0; x < _NbrIO; x++) {
        DumpLinker(_IO[x].getInput1()->getLink(), _IO[x].getInput1()->getTValue(), _IO[x].getInput1()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
        DumpLinker(_IO[x].getOutput()->getLink(), _IO[x].getOutput()->getTValue(), _IO[x].getOutput()->getValue(), nbr);
        nbr = DumpIgnored(nbr);
    }
}

void Composant::Build4081()
{
    And And1(_Name, 1, 2, 3);
    And And2(_Name, 5, 6, 4);
    And And3(_Name, 8, 9, 10);
    And And4(_Name, 13, 12, 11);

    _And.push_back(And1);
    _And.push_back(And2);
    _And.push_back(And3);
    _And.push_back(And4);
    _NbrAnd = _NbrAnd + 4;
    _Type = COMP4081;
}

void Composant::Build4011()
{
    Nand Nand1(_Name, 1, 2, 3);
    Nand Nand2(_Name, 5, 6, 4);
    Nand Nand3(_Name, 8, 9, 10);
    Nand Nand4(_Name, 13, 12, 11);

    _Nand.push_back(Nand1);
    _Nand.push_back(Nand2);
    _Nand.push_back(Nand3);
    _Nand.push_back(Nand4);
    _NbrNand = _NbrNand + 4;
    _Type = COMP4011;
}

void Composant::Build4071()
{
    Or Or1(_Name, 1, 2, 3);
    Or Or2(_Name, 5, 6, 4);
    Or Or3(_Name, 8, 9, 10);
    Or Or4(_Name, 13, 12, 11);

    _Or.push_back(Or1);
    _Or.push_back(Or2);
    _Or.push_back(Or3);
    _Or.push_back(Or4);
    _NbrOr = _NbrOr + 4;
    _Type = COMP4071;
}

void Composant::Build4030()
{
    Xor Xor1(_Name, 1, 2, 3);
    Xor Xor2(_Name, 5, 6, 4);
    Xor Xor3(_Name, 8, 9, 10);
    Xor Xor4(_Name, 13, 12, 11);

    _Xor.push_back(Xor1);
    _Xor.push_back(Xor2);
    _Xor.push_back(Xor3);
    _Xor.push_back(Xor4);
    _NbrXor = _NbrXor + 4;
    _Type = COMP4030;
}

void Composant::Build4069()
{
    Not Not1(_Name, 1, 2);
    Not Not2(_Name, 3, 4);
    Not Not3(_Name, 5, 6);
    Not Not4(_Name, 9, 8);
    Not Not5(_Name, 11, 10);
    Not Not6(_Name, 13, 12);

    _Not.push_back(Not1);
    _Not.push_back(Not2);
    _Not.push_back(Not3);
    _Not.push_back(Not4);
    _Not.push_back(Not5);
    _Not.push_back(Not6);
    _NbrNot = _NbrNot + 6;
    _Type = COMP4069;
}

void Composant::Build4001()
{
    Nor Nor1(_Name, 1, 2, 3);
    Nor Nor2(_Name, 5, 6, 4);
    Nor Nor3(_Name, 8, 9, 10);
    Nor Nor4(_Name, 13, 12, 11);

    _Nor.push_back(Nor1);
    _Nor.push_back(Nor2);
    _Nor.push_back(Nor3);
    _Nor.push_back(Nor4);
    _NbrNor = _NbrNor + 4;
    _Type = COMP4001;
}

void Composant::BuildIO()
{
    IO io(_Name, 1, 2);

    _IO.push_back(io);
    _NbrIO++;
    _Type = COMPIO;
}
