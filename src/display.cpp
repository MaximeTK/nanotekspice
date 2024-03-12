/*
** EPITECH PROJECT, 2021
** display
** File description:
** display
*/

#include "system.hpp"

void System::Dump() const
{
    for (int a = 0; a < _NbrComposant; a++) {
        if (_ListComposant[a]->getType() != Composant::COMPIO) {
            std::cout << _ListComposant[a]->getName() << ":" << std::endl;
            std::cout << "Chipset: " << CheckTypeComposant((*(_ListComposant[a]))) << std::endl;
            _ListComposant[a]->LaunchDumpAnd();
            _ListComposant[a]->LaunchDumpNand();
            _ListComposant[a]->LaunchDumpOr();
            _ListComposant[a]->LaunchDumpNor();
            _ListComposant[a]->LaunchDumpXor();
            _ListComposant[a]->LaunchDumpNot();
        }
    }
    for (int a = 0; a < _NbrLink; a++) {
        if (_ListLink[a].getDisplayStatus() == 1) {
            std::cout << _ListLink[a].getName() << ":" << std::endl;
            if (_ListLink[a].getGate()->getType() == Gate::INPUT && _ListLink[a].getGate()->getTValue() != Gate::NOTDEFINED)
                std::cout << "Input - value: " << _ListLink[a].getGate()->getValue() << std::endl;
            if (_ListLink[a].getGate()->getType() == Gate::INPUT && _ListLink[a].getGate()->getTValue() == Gate::NOTDEFINED)
                std::cout << "Input - value: U" << std::endl;
            if (_ListLink[a].getGate()->getType() == Gate::TRUE)
                std::cout << "True - value: " << _ListLink[a].getGate()->getValue() << std::endl;
            if (_ListLink[a].getGate()->getType() == Gate::FALSE)
                std::cout << "False - value: " << _ListLink[a].getGate()->getValue() << std::endl;
            if (_ListLink[a].getGate()->getType() == Gate::OUTPUT && _ListLink[a].getGate()->getTValue() != Gate::NOTDEFINED)
                std::cout << "Output - value: " << _ListLink[a].getGate()->getValue() << std::endl;
            if (_ListLink[a].getGate()->getType() == Gate::OUTPUT && _ListLink[a].getGate()->getTValue() == Gate::NOTDEFINED)
                std::cout << "Output - value: U" << std::endl;
            if (_ListLink[a].getGate()->getLink() == Gate::LINKED)
                std::cout << "         pin #1: linked" << std::endl;
            if (_ListLink[a].getGate()->getLink() == Gate::NOTLINKED)
                std::cout << "         pin #1: notlinked" << std::endl;
        }
    }
}

void System::DisplayAddress() const
{
    for (int x = 0; x != _NbrLink; x++) {
        std::cout << _ListLink[x].getGate() << " "
                  << _ListLink[x].getName() << " "
                  << _ListLink[x].getLink() << " "
                  << _ListLink[x].getGate()->getValue() << std::endl;
    }
}

void System::DisplayLink() const
{
    for (int x = 0; x != _NbrLink; x++) {
        if (_ListLink[x].getGate()->getType() == Gate::INPUT) std::cout << "INPUT ";
        if (_ListLink[x].getGate()->getType() == Gate::OUTPUT) std::cout << "OUTPUT ";
        std::cout << _ListLink[x].getName() << " [" << _ListLink[x].getLink() << "]" << std::endl;
    }
}

void System::DisplayInput() const
{
    std::cout << "input(s):" << std::endl;
    for (int x = 0; x != _NbrLink; x++) {
        if (_ListLink[x].getGate()->getType() == Gate::INPUT && _ListLink[x].getDisplayStatus() == 1) {
            std::cout << "  ";
            for (int a = 0; _ListLink[x].getName()[a] != ':'; a++)
                std::cout << _ListLink[x].getName()[a];
            if (_ListLink[x].getGate()->getTValue() != Gate::NOTDEFINED)
                std::cout << ": " << _ListLink[x].getGate()->getValue() << std::endl;
            else std::cout << ": U" << std::endl;
        }
        if (_ListLink[x].getGate()->getType() == Gate::TRUE && _ListLink[x].getDisplayStatus() == 1) {
            std::cout << "  ";
            for (int a = 0; _ListLink[x].getName()[a] != ':'; a++)
                std::cout << _ListLink[x].getName()[a];
            if (_ListLink[x].getGate()->getTValue() != Gate::NOTDEFINED)
                std::cout << ": " << _ListLink[x].getGate()->getValue() << std::endl;
            else std::cout << ": U" << std::endl;
        }
        if (_ListLink[x].getGate()->getType() == Gate::FALSE && _ListLink[x].getDisplayStatus() == 1) {
            std::cout << "  ";
            for (int a = 0; _ListLink[x].getName()[a] != ':'; a++)
                std::cout << _ListLink[x].getName()[a];
            if (_ListLink[x].getGate()->getTValue() != Gate::NOTDEFINED)
                std::cout << ": " << _ListLink[x].getGate()->getValue() << std::endl;
            else std::cout << ": U" << std::endl;
        }
    }
}

void System::DisplayOutput() const
{
    std::cout << "output(s):" << std::endl;
    for (int x = 0; x != _NbrLink; x++) {
        if (_ListLink[x].getGate()->getType() == Gate::OUTPUT && _ListLink[x].getDisplayStatus() == 1) {
            std::cout << "  ";
            for (int a = 0; _ListLink[x].getName()[a] != ':'; a++)
                std::cout << _ListLink[x].getName()[a];
            if (_ListLink[x].getGate()->getTValue() != Gate::NOTDEFINED)
                std::cout << ": " << _ListLink[x].getGate()->getValue() << std::endl;
            else std::cout << ": U" << std::endl;
        }
    }
}
