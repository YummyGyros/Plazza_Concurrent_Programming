/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** PizzaDefinitions
*/

#ifndef PIZZADEFINITIONS_HPP_
#define PIZZADEFINITIONS_HPP_

#include <map>
#include <string>

enum PizzaType
{
    Regina = 1 ,
    Margarita = 2 ,
    Americana = 4 ,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8 ,
    XXL = 16
};

const std::map<std::string, PizzaType> pizzaTypes = {
    { "regina", Regina },
    { "margarita", Margarita },
    { "americana", Americana },
    { "fantasia", Fantasia }
};

const std::map<std::string, PizzaSize> pizzaSizes = {
    { "S", S },
    { "M", M },
    { "L", L },
    { "XL", XL },
    { "XXL", XXL}
};

#endif /* !PIZZADEFINITIONS_HPP_ */
