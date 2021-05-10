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
                          "\tmultiplier\t[float]:\tpizze's cooking time will be multiplied with this argument.\n"
                          "\tcooks\t\t[std::size_t]:\tnumber of cooks per kitchen.\n"
                          "\trestock\t\t[std::size_t]:\trestock time of the kitchen's ingredients.\n"
                          "OPTIONS\n"
                          "\t-h --help\t Display usage";

void usage(std::ostream &stream)
{
    stream << USAGE << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2)
        if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help") {
            usage(std::cout);
            return 0;
        }
    if (ac != 4) {
        std::cerr << USAGE << std::endl;
        usage(std::cerr);
        return 84;
    }
    try {
        Reception recep(av);
    } catch (std::invalid_argument &e) {
        std::cerr << "error from function " << e.what() << ": at least one argument is in invalid." << std::endl << std::endl;
        usage(std::cerr);
        return 84;
    }
    return 0;
}
