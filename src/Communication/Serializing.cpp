/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Serialize
*/

#include "Serializing.hpp"

pizza_order_t Serializing::unpack(pizza_order_t order)
{
    return order;
}

std::unordered_map<Ingredients, std::size_t> Serializing::unpack(status_t stock)
{
    std::unordered_map<Ingredients, std::size_t> fridge {
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

pizza_order_t Serializing::pack(Pizza pizza, int myid)
{
    return {1, myid,pizza.getType(), pizza.getSize()};
}

status_t Serializing::pack(std::unordered_map<Ingredients, std::size_t> stock)
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
