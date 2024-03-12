/*
** EPITECH PROJECT, 2021
** nano
** File description:
** nano
*/

#include "system.hpp"

System::System()
{
    this->_NbrLineFile = 0;
    this->_NbrLink = 0;
    this->_NbrGate = 0;
    this->_NbrComposant = 0;
}

System::~System()
{
}

int System::my_strlen(std::string const str, std::string const research)
{
    int x = 0;

    for (int a = 0; str[a] != '\0' && research[x] != '\0'; a++) {
        if (str[a] == research[x]) x++;
        else x = 0;
    }
    if (research[x] == '\0' && x != 0) return (0);
    return (84);
}

void System::Initialisation()
{
    int x = 0;
    int status = 0;
    std::string name("");

    try {
        if (_NbrLineFile == 0) throw std::string("ERROR : File Empty !");
        for (; x < _NbrLineFile && my_strlen(_File[x], ".chipsets:\n") != 0; x++);
        if (x >= _NbrLineFile) throw std::string("ERROR : Chipset part not found !");
        for (x++ ; x < _NbrLineFile && my_strlen(_File[x], ".links:\n") != 0; x++) {
            status = CheckStatus(_File[x]);
            if (status != 84) name = CheckName(_File[x]);
            if (status == 1 && name != "INVALID") NewVariable(name, Gate::INPUT);
            if (status == 2 && name != "INVALID") NewVariable(name, Gate::OUTPUT);
            if (status == 3 && name != "INVALID") NewVariable(name, Gate::TRUE);
            if (status == 4 && name != "INVALID") NewVariable(name, Gate::FALSE);
            if (status == 4081 && name != "INVALID") NewComponant(name, "4081");
            if (status == 4011 && name != "INVALID") NewComponant(name, "4011");
            if (status == 4071 && name != "INVALID") NewComponant(name, "4071");
            if (status == 4030 && name != "INVALID") NewComponant(name, "4030");
            if (status == 4069 && name != "INVALID") NewComponant(name, "4069");
            if (status == 4001 && name != "INVALID") NewComponant(name, "4001");
        }
        if (x >= _NbrLineFile) throw std::string("ERROR : Link part not found !");
        for (; x < _NbrLineFile; x++) {
            if (research_link(TakeLink(_File[x]), TakeSecondLink(_File[x])) == 84)
                research_Gate(TakeLink(_File[x]), TakeSecondLink(_File[x]));
        }
    }
    catch (std::string const& chaine) {
        std::cerr << chaine << std::endl;
        exit(84);
    }
}

void System::Launch()
{
    std::string line;
    int tick = 0;

    ReloadGate();
    for (int x = 0; x != getNbrComposant(); x++) getListComposant()[x]->Reload();
    for (; line != "exit";) {
        std::cout << "> ";
        std::cin >> line;
        if (line == "\0" || line == "") {
            exit(0);
        }
        if (line == "simulate") {
            ReloadGate();
            for (int x = 0; x != getNbrComposant(); x++) getListComposant()[x]->Reload();
            for (int x = 0; x != getNbrComposant(); x++) getListComposant()[x]->Reload();
            tick++;
        }
        else if (line == "display") {
            std::cout << "tick: " << tick << std::endl;
            DisplayInput();
            DisplayOutput();
        }
        else if (line == "dump") Dump();
        else if (line == "exit") exit(0);
        else CheckInput(line);
        line = "";
    }
}
