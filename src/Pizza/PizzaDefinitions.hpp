/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** PizzaDefinitions
*/

#ifndef PIZZADEFINITIONS_HPP_
#define PIZZADEFINITIONS_HPP_

#include <unordered_map>
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

const std::unordered_map<PizzaType, std::string> pizzaTypesToString = {
    { Regina, "regina", },
    { Margarita, "margarita" },
    { Americana, "americana" },
    { Fantasia, "fantasia" }
};

const std::unordered_map<PizzaSize, std::string> pizzaSizesToString = {
    { S, "S" },
    { M, "M" },
    { L, "L" },
    { XL, "XL" },
    { XXL, "XXL" }
};

const std::unordered_map<std::string, PizzaType> pizzaTypes = {
    { "regina", Regina },
    { "margarita", Margarita },
    { "americana", Americana },
    { "fantasia", Fantasia }
};

const std::unordered_map<std::string, PizzaSize> pizzaSizes = {
    { "S", S },
    { "M", M },
    { "L", L },
    { "XL", XL },
    { "XXL", XXL}
};

#endif /* !PIZZADEFINITIONS_HPP_ */
