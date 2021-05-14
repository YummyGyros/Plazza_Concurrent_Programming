/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Serializing
*/

#ifndef SERIALIZING_HPP_
#define SERIALIZING_HPP_

#include "MessageQueue.hpp"

enum ingredients_e
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

static const std::map<PizzaType, std::vector<ingredients_e>> Recipe = { 
    {Regina, {tomato, gruyere}},
    {Margarita, {tomato, gruyere, ham, mushrooms}},
    {Americana, {tomato, gruyere, steak}},
    {Fantasia, {tomato, eggplant, goatCheese, chiefLove}}
};

class Serializing {
    public:
        Serializing();
        ~Serializing();

        pizza_order_t pack(Pizza pizza);
        status_t pack(std::map<ingredients_e, std::size_t> stock);

        Pizza unpack(pizza_order_t pizza);
        std::map<ingredients_e, std::size_t> unpack(status_t stock);

    protected:
    private:
};

#endif /* !SERIALIZING_HPP_ */
