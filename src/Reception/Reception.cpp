/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Reception
*/

#include "Reception.hpp"
#include "PizzaError.hpp"
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

void Reception::start()
{
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.compare("status") == 0)
            displayStatus();
        else
            manageOrder(line);
    }
}

// hésitez pas à enlever cette fonction si jamais vous avez besoin de faire vos trucs dans start directement
void Reception::manageOrder(const std::string &line)
{
    std::vector<Pizza> pizze = parseOrder(line);
    // for (auto const &pizza : pizze)
        // std::cout << "Pizza:\n\ttype:\t" << pizza.getPizzaType() << "\n\tsize:\t" << pizza.getPizzaSize() << std::endl;
}

void Reception::displayStatus()
{
    std::cout << "Status information should be displayed here." << std::endl;
}

std::vector<Pizza> Reception::parseOrder(const std::string &line)
{
    std::stringstream stream(line);
    std::string segment;
    std::vector<Pizza> pizze;

    while (std::getline(stream, segment, ';'))
        for (const auto &pizza: parsePizza(segment))
            pizze.push_back(pizza);
    return pizze;
}

int Reception::checkLastArg(std::string &tmp)
{
    if (tmp.length() < 2)
        return -1;
    if (tmp[0] != 'x')
        return -1;
    if (tmp[1] < '1' || tmp[1] > '9')
        return -1;
    for (int i = 1; tmp[i]; i++)
        if (tmp[i] < '0' || tmp[i] > '9')
            return -1;
    tmp.replace(0, 1, "0");
    return stod(tmp);
}

std::vector<Pizza> Reception::parsePizza(const std::string &segment)
{
    std::string tmp;
    std::stringstream stream(segment);
    Pizza pizza;
    std::vector<Pizza> pizze;
    int quantity;

    stream >> tmp;
    if (pizzaTypes.find(tmp) == pizzaTypes.end())
        throw PizzaError("size", tmp);
    pizza.setPizzaType(pizzaTypes.find(tmp)->second);

    stream >> tmp;
    if (pizzaSizes.find(tmp) == pizzaSizes.end())
        throw PizzaError("type", tmp);
    pizza.setPizzaSize(pizzaSizes.find(tmp)->second);

    stream >> tmp;
    if ((quantity = checkLastArg(tmp)) == -1)
        throw PizzaError("quantity", tmp);

    for (int i = 0; i < quantity; i++) {
        Pizza tmp(pizza);
        pizze.push_back(tmp);
    }
    return pizze;
}