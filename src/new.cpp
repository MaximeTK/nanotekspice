/*
** EPITECH PROJECT, 2021
** new
** File description:
** new
*/

#include "system.hpp"

void System::NewComponant(std::string const name, std::string const type)
{
    Composant *composant = new Composant(name);

    if (type == "4081") {
        composant->Build4081();
        ComponantListAdder(composant->getAnd()[0].getInput1(), composant->getAnd()[0].getInput2(), composant->getAnd()[0].getOutput());
        ComponantListAdder(composant->getAnd()[1].getInput1(), composant->getAnd()[1].getInput2(), composant->getAnd()[1].getOutput());
        ComponantListAdder(composant->getAnd()[2].getInput1(), composant->getAnd()[2].getInput2(), composant->getAnd()[2].getOutput());
        ComponantListAdder(composant->getAnd()[3].getInput1(), composant->getAnd()[3].getInput2(), composant->getAnd()[3].getOutput());
        _ListComposant.push_back(composant);
        _NbrGate = _NbrGate + 12;
        _NbrComposant++;
    }
    if (type == "4011") {
        composant->Build4011();
        ComponantListAdder(composant->getNand()[0].getInput1(), composant->getNand()[0].getInput2(), composant->getNand()[0].getOutput());
        ComponantListAdder(composant->getNand()[1].getInput1(), composant->getNand()[1].getInput2(), composant->getNand()[1].getOutput());
        ComponantListAdder(composant->getNand()[2].getInput1(), composant->getNand()[2].getInput2(), composant->getNand()[2].getOutput());
        ComponantListAdder(composant->getNand()[3].getInput1(), composant->getNand()[3].getInput2(), composant->getNand()[3].getOutput());
        _ListComposant.push_back(composant);
        _NbrGate = _NbrGate + 12;
        _NbrComposant++;
    }
    if (type == "4071") {
        composant->Build4071();
        ComponantListAdder(composant->getOr()[0].getInput1(), composant->getOr()[0].getInput2(), composant->getOr()[0].getOutput());
        ComponantListAdder(composant->getOr()[1].getInput1(), composant->getOr()[1].getInput2(), composant->getOr()[1].getOutput());
        ComponantListAdder(composant->getOr()[2].getInput1(), composant->getOr()[2].getInput2(), composant->getOr()[2].getOutput());
        ComponantListAdder(composant->getOr()[3].getInput1(), composant->getOr()[3].getInput2(), composant->getOr()[3].getOutput());
        _ListComposant.push_back(composant);
        _NbrGate = _NbrGate + 12;
        _NbrComposant++;
    }
    if (type == "4030") {
        composant->Build4030();
        ComponantListAdder(composant->getXor()[0].getInput1(), composant->getXor()[0].getInput2(), composant->getXor()[0].getOutput());
        ComponantListAdder(composant->getXor()[1].getInput1(), composant->getXor()[1].getInput2(), composant->getXor()[1].getOutput());
        ComponantListAdder(composant->getXor()[2].getInput1(), composant->getXor()[2].getInput2(), composant->getXor()[2].getOutput());
        ComponantListAdder(composant->getXor()[3].getInput1(), composant->getXor()[3].getInput2(), composant->getXor()[3].getOutput());
        _ListComposant.push_back(composant);
        _NbrGate = _NbrGate + 12;
        _NbrComposant++;
    }
    if (type == "4069") {
        composant->Build4069();
        ComponantListAdder(composant->getNot()[0].getInput1(), NULL, composant->getNot()[0].getOutput());
        ComponantListAdder(composant->getNot()[1].getInput1(), NULL, composant->getNot()[1].getOutput());
        ComponantListAdder(composant->getNot()[2].getInput1(), NULL, composant->getNot()[2].getOutput());
        ComponantListAdder(composant->getNot()[3].getInput1(), NULL, composant->getNot()[3].getOutput());
        ComponantListAdder(composant->getNot()[4].getInput1(), NULL, composant->getNot()[4].getOutput());
        ComponantListAdder(composant->getNot()[5].getInput1(), NULL, composant->getNot()[5].getOutput());
        _ListComposant.push_back(composant);
        _NbrGate = _NbrGate + 12;
        _NbrComposant++;
    }
    if (type == "4001") {
        composant->Build4001();
        ComponantListAdder(composant->getNor()[0].getInput1(), composant->getNor()[0].getInput2(), composant->getNor()[0].getOutput());
        ComponantListAdder(composant->getNor()[1].getInput1(), composant->getNor()[1].getInput2(), composant->getNor()[1].getOutput());
        ComponantListAdder(composant->getNor()[2].getInput1(), composant->getNor()[2].getInput2(), composant->getNor()[2].getOutput());
        ComponantListAdder(composant->getNor()[3].getInput1(), composant->getNor()[3].getInput2(), composant->getNor()[3].getOutput());
        _ListComposant.push_back(composant);
        _NbrGate = _NbrGate + 12;
        _NbrComposant++;
    }
}

void System::ComponantListAdder(Gate *Input1, Gate *Input2, Gate *Output)
{
    if (Input1 != NULL) _ListGate.push_back(Input1);
    if (Input2 != NULL) _ListGate.push_back(Input2);
    if (Output != NULL) _ListGate.push_back(Output);
}

void System::NewIO(int a, int b)
{
    Composant *composant = new Composant(_ListLink[a].getName() + _ListLink[b].getName());

    composant->BuildIO();
    ComponantListAdder(composant->getIO()[0].getInput1(), NULL, composant->getIO()[0].getOutput());
    _ListComposant.push_back(composant);
    _NbrGate = _NbrGate + 2;
    _NbrComposant++;
    if (_ListLink[a].getGate()->getType() == Gate::INPUT)
        research_link(_ListLink[a].getName(), _ListLink[a].getName() + _ListLink[b].getName() + ":1");
    if (_ListLink[b].getGate()->getType() == Gate::INPUT)
        research_link(_ListLink[b].getName(), _ListLink[a].getName() + _ListLink[b].getName() + ":1");
    if (_ListLink[a].getGate()->getType() == Gate::OUTPUT)
        research_link(_ListLink[a].getName(), _ListLink[a].getName() + _ListLink[b].getName() + ":2");
    if (_ListLink[b].getGate()->getType() == Gate::OUTPUT)
        research_link(_ListLink[b].getName(), _ListLink[a].getName() + _ListLink[b].getName() + ":2");
    _ListLink[a].getGate()->changeTValue(Gate::NOTDEFINED);
    _ListLink[b].getGate()->changeTValue(Gate::NOTDEFINED);
    if (_ListLink[a].getGate()->getType() == Gate::TRUE ||
        _ListLink[a].getGate()->getType() == Gate::FALSE)
        _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
    if (_ListLink[b].getGate()->getType() == Gate::TRUE ||
        _ListLink[b].getGate()->getType() == Gate::FALSE)
        _ListLink[b].getGate()->changeTValue(Gate::DEFINED);
}

void System::NewVariable(std::string const name, Gate::TGate type)
{
    Link link(name, "", type);

    this->_ListLink.push_back(link);
    this->_NbrLink++;
}
