/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Main
*/

#include "Reception.hpp"
#include <iostream>

const std::string USAGE = "USAGE\n"
                          "\tPizzeria simulation implementing processes, threads, mutex and much more.\n\n"
                          "./plazza <multiplier> <cooks> <restock>\n\n"
                          "\tmultiplier\t[float]:\tpizze's cooking time will be multiplied with this parameter.\n"
                          "\tcooks\t\t[std::size_t]:\tnumber of cooks per kitchen.\n"
                          "\trestock\t\t[std::size_t]:\trestock time of the ingredients of the kitchens.\n"
                          "OPTIONS\n"
                          "\t-h --help\t Display usage";

void usage()
{
    std::cout << USAGE << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2)
        if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help") {
            usage();
            return 0;
        }
    if (ac != 4) {
        usage();
        return 84;
    }
    return 0;
}
