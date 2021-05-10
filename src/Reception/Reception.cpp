/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Reception
*/

#include "Reception.hpp"
#include <string>
#include <iostream>
#include <sstream>

Reception::Reception(char **av)
{
    _timeMultiplier = std::stof(av[1]);
    _cooksPerKitchen = std::stoi(av[2]);
    _restockTime = std::stoi(av[3]);
}

Reception::~Reception()
{
}

float Reception::getTimeMultiplier() const
{
    return _timeMultiplier;
}

std::size_t Reception::getCooksPerKitchen() const
{
    return _cooksPerKitchen;
}

std::size_t Reception::getRestockTime() const
{
    return _restockTime;
}

void Reception::takeOrders()
{
    std::string line;

    while (std::getline(std::cin, line)) {
        parseOrder(line);
    }
}

std::vector<Pizza> Reception::parseOrder(const std::string &line)
{
    std::stringstream stream(line);
    std::string segment;
    std::vector<Pizza> pizze;

    std::cout << line << std::endl;
    while (std::getline(stream, segment, ';')) {
        parsePizza(segment);
    }
    return pizze;
}

Pizza Reception::parsePizza(const std::string &segment)
{
    std::string tmp;
    std::stringstream stream(segment);
    Pizza pizza;

    while (std::getline(stream, tmp, ' ')) {
        std::cout << "portion: " << tmp << std::endl;
        //parse every bit into a pizza here.
    }
    return pizza;
}