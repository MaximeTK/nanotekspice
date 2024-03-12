/*
** EPITECH PROJECT, 2021
** system
** File description:
** system
*/

#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include "IO.hpp"
#include "gate.hpp"
#include "nano.hpp"
#include "nand.hpp"
#include "and.hpp"
#include "link.hpp"
#include "composant.hpp"

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

class System
{
public:
    System();
    ~System();
    //function system
    int my_strlen(std::string const str, std::string const research);
    //get
    int getNbrLineFile() const { return (_NbrLineFile); }
    int getNbrLink() const { return (_NbrLink); }
    int getNbrGate() const { return (_NbrGate); }
    int getNbrComposant() const { return (_NbrComposant); }
    std::vector<std::string> getFile() const { return (_File); }
    std::vector<Link> getListLink() const { return (_ListLink); }
    std::vector<Gate *> getListGate() const { return (_ListGate); }
    std::vector<Gate> getSave() const { return (_Save); }
    std::vector<Composant *> getListComposant() const { return (_ListComposant); }
    //file
    void AddLine(std::string const line);
    void take_file(char const *str);
    //Adder
    void ComponantListAdder(Gate *Input1, Gate *Input2, Gate *Output);
    void NewIO(int a, int b);
    void NewComponant(std::string const name, std::string const type);
    void NewVariable(std::string const name, Gate::TGate type);
    //search chipset part
    std::string CheckName(std::string const str);
    std::string CheckTypeComposant(Composant composant) const;
    int CheckStatus(std::string const str);
    //search link part
    int CheckAllGates(std::string const research);
    int research_Gate(std::string str, std::string research);
    int research_link(std::string str, std::string research);
    std::string TakeSecondLink(std::string const str);
    std::string TakeLink(std::string const str);
    //Loading
    void Initialisation();
    //display
    void Dump() const;
    void DisplayAddress() const;
    void DisplayLink() const;
    void DisplayGate() const;
    void DisplayInput() const;
    void DisplayOutput() const;
    //launcher
    int research_linkName(std::string research, std::string value);
    void CheckInput(std::string const str);
    void ReloadGate();
    void Launch();
private:
    std::vector<Gate *> _ListGate;
    std::vector<Gate> _Save;
    std::vector<Link> _ListLink;
    std::vector<Composant *> _ListComposant;
    std::vector<std::string> _File;
    int _NbrLineFile;
    int _NbrLink;
    int _NbrGate;
    int _NbrComposant;
};

#endif
