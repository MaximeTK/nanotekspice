/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <string>
#include <vector>
#include "nano.hpp"
#include "and.hpp"
#include "nand.hpp"
#include "or.hpp"
#include "xor.hpp"
#include "not.hpp"
#include "nor.hpp"
#include "IO.hpp"

#ifndef COMPOSANT_HPP_
#define COMPOSANT_HPP_

class Composant
{
public:
    typedef enum type {
        UNDEFINED,
        COMP4081,
        COMP4011,
        COMP4071,
        COMP4030,
        COMP4069,
        COMP4001,
        COMPIO
    } CType;
    Composant(std::string const name);
    ~Composant();
    void DumpSelector(Gate::TValue tvalue, bool Value, int nbr) const;
    void DumpLinker(Gate::TLink link, Gate::TValue tvalue, bool Value, int nbr) const;
    int DumpIgnored(int nbr) const;
    int DumpGate(std::vector<Nano> nano, int x, int nbr) const;
    void LaunchDumpAnd() const;
    void LaunchDumpNand() const;
    void LaunchDumpOr() const;
    void LaunchDumpNor() const;
    void LaunchDumpXor() const;
    void LaunchDumpNot() const;
    void LaunchDumpIO() const;
    void Reload();
    std::string getName() const { return (_Name); }
    CType getType() const { return (_Type); }
    //AND
    void Build4081();
    std::vector<And> getAnd() { return (this->_And); }
    int getNbrAnd() const { return (this->_NbrAnd); }
    void changeAndInput1(int x, Gate *const input1) { _And[x].changeInput1(input1); }
    void changeAndInput2(int x, Gate *const input2) { _And[x].changeInput2(input2); }
    //NAND
    void Build4011();
    std::vector<Nand> getNand() { return (this->_Nand); }
    int getNbrNand() const { return (this->_NbrNand); }
    void changeNandInput1(int x, Gate *const input1) { _Nand[x].changeInput1(input1); }
    void changeNandInput2(int x, Gate *const input2) { _Nand[x].changeInput2(input2);}
    //OR
    void Build4071();
    std::vector<Or> getOr() { return (this->_Or); }
    int getNbrOr() const { return (this->_NbrOr); }
    void changeOrInput1(int x, Gate *const input1) { _Or[x].changeInput1(input1); }
    void changeOrInput2(int x, Gate *const input2) { _Or[x].changeInput2(input2); }
    //XOR
    void Build4030();
    std::vector<Xor> getXor() { return (this->_Xor); }
    int getNbrXor() const { return (this->_NbrXor); }
    void changeXorInput1(int x, Gate *const input1) { _Xor[x].changeInput1(input1); }
    void changeXorInput2(int x, Gate *const input2) { _Xor[x].changeInput2(input2); }
    //NOT
    void Build4069();
    std::vector<Not> getNot() { return (this->_Not); }
    int getNbrNot() const { return (this->_NbrNot); }
    void changeNotInput1(int x, Gate *const input1) { _Not[x].changeInput1(input1); }
    //OR
    void Build4001();
    std::vector<Nor> getNor() { return (this->_Nor); }
    int getNbrNor() const { return (this->_NbrNor); }
    void changeNorInput1(int x, Gate *const input1) { _Nor[x].changeInput1(input1); }
    void changeNorInput2(int x, Gate *const input2) { _Nor[x].changeInput2(input2); }
    void BuildIO();
    std::vector<IO> getIO() { return (this->_IO); }
    int getNbrIO() const { return (this->_NbrIO); }
    void changeIOInput1(Gate *const input1) { _IO[0].changeInput1(input1); }
    void changeIOOutput1(Gate *const output1) { _IO[0].changeOutput1(output1); }
private:
    std::string _Name;
    CType _Type;
    std::vector<And> _And;
    int _NbrAnd;
    std::vector<Nand> _Nand;
    int _NbrNand;
    std::vector<Or> _Or;
    int _NbrOr;
    std::vector<Xor> _Xor;
    int _NbrXor;
    std::vector<Not> _Not;
    int _NbrNot;
    std::vector<Nor> _Nor;
    int _NbrNor;
    std::vector<IO> _IO;
    int _NbrIO;
};

#endif
