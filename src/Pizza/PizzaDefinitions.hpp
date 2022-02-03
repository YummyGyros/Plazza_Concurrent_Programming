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
#include <vector>

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

enum Ingredients
{
    tomato,
    gruyere,
    ham,
    mushrooms,
    steak,
    eggplant,
    goatCheese,
    chiefLove
};

const std::unordered_map<Ingredients, std::string> ingredientsToString = {
    { tomato, "tomato", },
    { gruyere, "gruyere" },
    { ham, "ham" },
    { mushrooms, "mushrooms" },
    { steak, "steak" },
    { eggplant, "eggplant" },
    { goatCheese, "goatCheese" },
    { chiefLove, "chiefLove" }
};

static const std::unordered_map<PizzaType, std::vector<Ingredients>> recipes = {
    {Regina, {tomato, gruyere}},
    {Margarita, {tomato, gruyere, ham, mushrooms}},
    {Americana, {tomato, gruyere, steak}},
    {Fantasia, {tomato, eggplant, goatCheese, chiefLove}}
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

static const std::unordered_map<PizzaType, float> timeToCook = {
    {Margarita, {1000}},
    {Regina, {2000}},
    {Americana, {2000}},
    {Fantasia, {4000}}
};

#endif /* !PIZZADEFINITIONS_HPP_ */
