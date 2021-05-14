/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Serialize
*/

#include "Serializing.hpp"

Pizza Serializing::unpack(pizza_order_t pizza)
{
    Pizza newPizza;

    newPizza.setPizzaType(pizza.type);
    newPizza.setPizzaSize(pizza.size);
    return newPizza;
}

std::map<ingredients_e, std::size_t> Serializing::unpack(status_t stock)
{
    std::map<ingredients_e, std::size_t> fridge {
        {tomato, stock.tomato},
        {gruyere, stock.gruyere},
        {ham, stock.ham},
        {mushrooms, stock.mushrooms},
        {steak, stock.steak},
        {eggplant, stock.eggplant},
        {goatCheese, stock.goatCheese},
        {chiefLove, stock.chiefLove}
    };

    return fridge;
}

pizza_order_t Serializing::pack(Pizza pizza)
{
    return {1, pizza.getPizzaType(), pizza.getPizzaSize()};
}

status_t Serializing::pack(std::map<ingredients_e, std::size_t> stock)
{
    return {1, stock[tomato], stock[gruyere], stock[ham], stock[mushrooms],
    stock[steak], stock[eggplant], stock[goatCheese], stock[chiefLove], 1};
}

Serializing::Serializing()
{
}

Serializing::~Serializing()
{
}
