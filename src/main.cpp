/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "system.hpp"

int main (int ac, char **av)
{
    System system;

    if (ac != 2) return (84);
    system.take_file(av[1]);
    system.Initialisation();
    system.Launch();
    return 0;
}
