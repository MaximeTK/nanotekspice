/*
** EPITECH PROJECT, 2021
** reload
** File description:
** reload
*/

#include "system.hpp"

void System::ReloadGate()
{
    int a = 0;

    for (; a < _NbrLink; a++) {
        if (_ListLink[a].getGate()->getTWaiting() == Gate::WAIT_0) {
            _ListLink[a].getGate()->changeTWaiting(Gate::NOTHING);
            _ListLink[a].getGate()->changeValue(0);
            _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
        }
        if (_ListLink[a].getGate()->getTWaiting() == Gate::WAIT_1) {
            _ListLink[a].getGate()->changeTWaiting(Gate::NOTHING);
            _ListLink[a].getGate()->changeValue(1);
            _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
        }
        if (_ListLink[a].getGate()->getTWaiting() == Gate::WAITUNDEFINED) {
            _ListLink[a].getGate()->changeTWaiting(Gate::NOTHING);
            _ListLink[a].getGate()->changeValue(0);
            _ListLink[a].getGate()->changeTValue(Gate::NOTDEFINED);
        }
        if (_ListLink[a].getGate()->getType() == Gate::TRUE) {
            _ListLink[a].getGate()->changeTWaiting(Gate::NOTHING);
            _ListLink[a].getGate()->changeValue(1);
            _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
        }
        if (_ListLink[a].getGate()->getType() == Gate::FALSE) {
            _ListLink[a].getGate()->changeTWaiting(Gate::NOTHING);
            _ListLink[a].getGate()->changeValue(0);
            _ListLink[a].getGate()->changeTValue(Gate::DEFINED);
        }
    }
}
