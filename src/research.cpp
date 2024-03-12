/*
** EPITECH PROJECT, 2021
** research
** File description:
** research
*/

#include "system.hpp"

int System::research_Gate(std::string str, std::string research)
{
    int a = 0;

    for (a = 0; a < _NbrGate && _ListGate[a]->getName() != str; a++);
    if (a >= _NbrGate) return (84);
    if (_ListGate[a]->getType() == Gate::INPUT) {
        std::string tmp = str;
        str = research;
        research = tmp;
    }
    Link link(str, research, Gate::OUTPUT);

    for (a = 0; a < _NbrGate && _ListGate[a]->getName() != str; a++);
    if (a >= _NbrGate) return (84);
    link.changeGate(_ListGate[a]);
    link.getGate()->changeType(Gate::OUTPUT);
    link.changeDisplayStatus(0);
    link.changeName(str);
    _ListLink.push_back(link);
    _NbrLink++;
    CheckAllGates(research);
    return (0);
}

int System::research_link(std::string str, std::string research)
{
    int a = 0;
    int b = 0;
    int change = 0;

    for(; a < _NbrLink && _ListLink[a].getName() != str; a++);
    for(; b < _NbrGate && _ListGate[b]->getName() != research; b++);
    if (b < _NbrGate && a < _NbrLink) {
        if (_ListLink[a].getName() == str && _ListGate[b]->getName() == research) {
            if (_ListLink[a].getGate()->getType() == Gate::TRUE) change = 1;
            if (_ListLink[a].getGate()->getType() == Gate::FALSE) change = 2;
            _ListLink[a].changeGate(_ListGate[b]);
            if (change == 1) _ListLink[a].getGate()->changeType(Gate::TRUE);
            if (change == 2) _ListLink[a].getGate()->changeType(Gate::FALSE);
            _ListLink[a].changeLink(_ListGate[b]->getName());
            _ListLink[a].getGate()->changeLink(Gate::LINKED);
            _ListLink[a].getGate()->changeTValue(Gate::NOTDEFINED);
            return (0);
        }
    }
    for(a = 0; a < _NbrLink && _ListLink[a].getName() != research; a++);
    for(b = 0; b < _NbrGate && _ListGate[b]->getName() != str; b++);
    if (b < _NbrGate && a <  _NbrLink) {
        if (_ListLink[a].getName() == research && _ListGate[b]->getName() == str) {
            if (_ListLink[a].getGate()->getType() == Gate::TRUE) change = 1;
            if (_ListLink[a].getGate()->getType() == Gate::FALSE) change = 2;
            _ListLink[a].changeGate(_ListGate[b]);
            if (change == 1) _ListLink[a].getGate()->changeType(Gate::TRUE);
            if (change == 2) _ListLink[a].getGate()->changeType(Gate::FALSE);
            _ListLink[a].changeLink(_ListGate[b]->getName());
            _ListLink[a].getGate()->changeLink(Gate::LINKED);
            _ListLink[a].getGate()->changeTValue(Gate::NOTDEFINED);
            return (0);
        }
    }
    for(a = 0; a < _NbrLink && _ListLink[a].getName() != research; a++);
    for(b = 0; b < _NbrLink && _ListLink[b].getName() != str; b++);
    if (b < _NbrLink && a < _NbrLink && _ListLink[a].getName() == research && _ListLink[b].getName() == str) {
        NewIO(a, b);
        return (0);
    }
    return (84);
}

std::string System::TakeSecondLink(std::string const str)
{
    std::string name("");
    int x = 0;

    for (; str[x] != '\0' && str[x] != '\n'; x++);
    for (; x > 0 && str[x] != ' '; x--);
    for (; str[x] != '\0' && str[x] == ' '; x++);
    for (; str[x] != '\0' && str[x] != '#' && str[x] != '\n'; x++) name = name + str[x];
    if (name == "") return ("INVALID");
    return (name);
}

std::string System::TakeLink(std::string const str)
{
    std::string name("");
    int x = 0;

    for (; str[x] != '\0' && str[x] == ' '; x++);
    if (str[x] == ' ') x++;
    for (; str[x] != '\0' && str[x] != ' ' && str[x] != '#' && str[x] != '\n'; x++) {
        name = name + str[x];
    }
    if (name == "") return ("INVALID");
    return (name);
}

int System::research_linkName(std::string research, std::string value)
{
    int a = 0;
    int access = 0;

    for(; a < _NbrLink && _ListLink[a].getName() != research; a++);
    if (a >= _NbrLink) return (84);
    if (_ListLink[a].getName() == research) access = 1;
    if (_ListLink[a].getGate()->getType() == Gate::INPUT) access++;
    if (access == 2) {
        if (value == "0") {
            _ListLink[a].getGate()->changeTWaiting(Gate::WAIT_0);
        }
        if (value == "1") {
            _ListLink[a].getGate()->changeTWaiting(Gate::WAIT_1);
        }
        if (value == "U") {
            _ListLink[a].getGate()->changeTWaiting(Gate::WAITUNDEFINED);
        }
        return (0);
    }
    return (84);
}
