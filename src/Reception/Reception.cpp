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

    stream >> tmp;
    // std::cout << "first parse: " << tmp << std::endl;
    if (pizzaTypes.find(tmp) != pizzaTypes.end())
        pizza.setPizzaType(pizzaTypes.find(tmp)->second);
    stream >> tmp;
    // std::cout << "second parse: " << tmp << std::endl;
    if (pizzaSizes.find(tmp) != pizzaSizes.end())
        pizza.setPizzaSize(pizzaSizes.find(tmp)->second);
    stream >> tmp;
    // std::cout << "third parse: " << tmp << std::endl;
    std::cout << "Pizza:\n\ttype: " << pizza.getPizzaType() << "\n\tsize: " << pizza.getPizzaSize() << std::endl;

    //parse last param
    //what do we do when pizza is invalid? bool in class? return null somehow?
    return pizza;
}