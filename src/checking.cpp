/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#include "system.hpp"

std::string System::CheckName(std::string const str)
{
    std::string name("");
    int x = 0;

    for (; str[x] != ' '; x++);
    for (; str[x] == ' '; x++);
    for (; str[x] != '\0' && str[x] != '#' && str[x] != '\n'; x++) name = name + str[x];
    if (name == "") return ("INVALID");
    return (name);
}

std::string System::CheckTypeComposant(Composant composant) const
{
    if (composant.getType() == Composant::COMP4081) return ("4081");
    if (composant.getType() == Composant::COMP4011) return ("4011");
    if (composant.getType() == Composant::COMP4071) return ("4071");
    if (composant.getType() == Composant::COMP4069) return ("4069");
    if (composant.getType() == Composant::COMP4001) return ("4001");
    return ("");
}

int System::CheckStatus(std::string str)
{
    int access = 0;
    int x = 0;
    std::string comp("");

    for (; str[x] != '\0'&& str[x] != ' ' && str[x] != '\n'; x++) {
        comp = comp + str[x];
    }
    if (x == 0) return 84;
    if (comp == "input") return (1);
    if (comp == "output") return (2);
    if (comp == "true") return (3);
    if (comp == "false") return (4);
    if (comp == "4071") return (4071);
    if (comp == "4081") return (4081);
    if (comp == "4011") return (4011);
    if (comp == "4030") return (4030);
    if (comp == "4069") return (4069);
    if (comp == "4001") return (4001);
    comp = str;
    for (x = 0; comp[x] != '\0' && comp[x] != '\n'; x++) {
        if (comp[x] != ' ') access = 1;
        if (comp[x] == '#') access = 0;
    }
    if (access == 1 && comp[x] == '\n') access = 0;
    comp[x] = '\0';
    if (access == 1) throw std::string("ERROR : Not found " + comp);
    return (84);
}

int System::CheckAllGates(std::string const research)
{
    int a = _NbrLink - 1;

    for (int x = 0; x < _NbrComposant; x++) {
        for (int c = 0; c < _NbrGate; c++) {
            if (c < _ListComposant[x]->getNbrAnd() && _ListComposant[x]->getAnd()[c].getInput1()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListComposant[x]->changeAndInput1(c, _ListLink[a].getGate());
                return (0);
            }
            if (c < _ListComposant[x]->getNbrAnd() && _ListComposant[x]->getAnd()[c].getInput2()->getName() == research) {
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListComposant[x]->changeAndInput2(c, _ListLink[a].getGate());
                _ListLink[a].changeDisplayStatus(0);
                return (0);
            }
            if (c < _ListComposant[x]->getNbrNand() && _ListComposant[x]->getNand()[c].getInput1()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListComposant[x]->changeNandInput1(c, _ListLink[a].getGate());
                return (0);
            }
            if (c < _ListComposant[x]->getNbrNand() && _ListComposant[x]->getNand()[c].getInput2()->getName() == research) {
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                _ListComposant[x]->changeNandInput2(c, _ListLink[a].getGate());
                _ListLink[a].changeDisplayStatus(0);
                return (0);
            }
            if (c < _ListComposant[x]->getNbrOr() && _ListComposant[x]->getOr()[c].getInput1()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                _ListComposant[x]->changeOrInput1(c, _ListLink[a].getGate());
                return (0);
            }
            if (c < _ListComposant[x]->getNbrOr() && _ListComposant[x]->getOr()[c].getInput2()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                _ListComposant[x]->changeOrInput2(c, _ListLink[a].getGate());
                return (0);
            }
            if (c < _ListComposant[x]->getNbrXor() && _ListComposant[x]->getXor()[c].getInput1()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                _ListComposant[x]->changeXorInput1(c, _ListLink[a].getGate());
                return (0);
            }
            if (c < _ListComposant[x]->getNbrXor() && _ListComposant[x]->getXor()[c].getInput2()->getName() == research) {
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListComposant[x]->changeXorInput2(c, _ListLink[a].getGate());
                _ListLink[a].changeDisplayStatus(0);
                return (0);
            }
            if (c < _ListComposant[x]->getNbrNot() && _ListComposant[x]->getNot()[c].getInput1()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListComposant[x]->changeNotInput1(c, _ListLink[a].getGate());
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                return (0);
            }
            if (c < _ListComposant[x]->getNbrNor() && _ListComposant[x]->getNor()[c].getInput1()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                _ListComposant[x]->changeNorInput1(c, _ListLink[a].getGate());
                return (0);
            }
            if (c < _ListComposant[x]->getNbrNor() && _ListComposant[x]->getNor()[c].getInput2()->getName() == research) {
                _ListLink[a].changeDisplayStatus(0);
                _ListLink[a].getGate()->changeLink(Gate::LINKED);
                _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
                _ListComposant[x]->changeNorInput2(c, _ListLink[a].getGate());
                return (0);
            }
        }
    }
    return (84);
}

void System::CheckInput(std::string const str)
{
    std::string name("");
    std::string value("");
    int x = 0;
    int limit = 0;

    for (; str[x] != '\0' && str[x] != '\n' && str[x] != '='; x++) name = name + str[x];
    if (str[x] != '\0') x++;
    for (; str[x] != '\0' && str[x] != '\n'; x++) value = value + str[x];
    for (; value[limit] != '\0'; limit++);
    if (limit != 1) return;
    else research_linkName(name + ":1", value);
}
