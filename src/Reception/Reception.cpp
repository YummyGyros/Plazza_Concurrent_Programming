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

int checkLastArg(std::string &tmp)
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

Pizza Reception::parsePizza(const std::string &segment)
{
    std::string tmp;
    std::stringstream stream(segment);
    Pizza pizza;
    int quantity;

    stream >> tmp;
    // std::cout << "first parse: " << tmp << std::endl;
    if (pizzaTypes.find(tmp) != pizzaTypes.end())
        pizza.setPizzaType(pizzaTypes.find(tmp)->second);
    stream >> tmp;
    // std::cout << "second parse: " << tmp << std::endl;
    if (pizzaSizes.find(tmp) != pizzaSizes.end())
        pizza.setPizzaSize(pizzaSizes.find(tmp)->second);
    stream >> tmp;
    quantity = checkLastArg(tmp);
    // std::cout << "third parse: " << tmp << std::endl;

    std::cout << "Pizza:\n\ttype: " << pizza.getPizzaType() << "\n\tsize: " << pizza.getPizzaSize() << std::endl << "\tquantity: " << quantity << std::endl;
    //parse last param
    //what do we do when pizza is invalid? bool in class? return null somehow?
    return pizza;
}