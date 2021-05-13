/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Serialize
*/

#include "Serializing.hpp"

pizza_order_t Serializing::pack(Pizza pizza)
{
    return {1, pizza.getPizzaType(), pizza.getPizzaSize()};
}

status_t Serializing::pack(std::map<ingredients_e, int> stock)
{
    return {1, stock[tomato], stock[gruyere], stock[ham], stock[mushrooms],
    stock[steak], stock[eggplant], stock[goatCheese], stock[chiefLove]};
}

Serializing::Serializing()
{
}

Serializing::~Serializing()
{
}
