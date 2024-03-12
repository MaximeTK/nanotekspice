/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <ostream>
#include <iostream>
#include <string>

#ifndef GATE_HPP_
#define GATE_HPP_

class Gate
{
public:
    typedef enum type {
        INPUT,
        OUTPUT,
        TRUE,
        FALSE,
        UNDEFINED
    } TGate;
    typedef enum link {
        NOTLINKED,
        LINKED
    } TLink;
    typedef enum value {
        NOTDEFINED,
        DEFINED
    } TValue;
    typedef enum waiting {
        NOTHING,
        WAITUNDEFINED,
        WAIT_0,
        WAIT_1
    } TWaiting;    
    Gate(std::string const Name,TGate Type, bool Value);
    ~Gate();
    void changeName(std::string Name) { _Name = Name; }
    std::string getName() { return (_Name); }
    TGate getType() const { return (_Type); }
    bool getValue() const { return (_Value); }
    TLink getLink() const { return (_Link); }
    TValue getTValue() const { return (_TValue); }
    TWaiting getTWaiting() const { return (_TWaiting); }
    void changeTGate(TGate tgate) { _Type = tgate; }
    void changeValue(bool value) { _Value = value; }
    void changeType(TGate type) { _Type = type; }
    void changeLink(TLink link) { _Link = link; }
    void changeTValue(TValue tvalue) { _TValue = tvalue; }
    void changeTWaiting(TWaiting waiting) { _TWaiting = waiting; }
protected:
    std::string _Name;
    TGate _Type;
    bool _Value;
    TWaiting _TWaiting;
    TLink _Link;
    TValue _TValue;
};
#endif
