/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Pizza
*/

#include "Pizza.hpp"

void Pizza::setPizzaType(const PizzaType type)
{
    _type = type;
}

PizzaType Pizza::getPizzaType() const
{
    return _type;
}

void Pizza::setPizzaSize(const PizzaSize size)
{
    _size = size;
}

PizzaSize Pizza::getPizzaSize() const
{
    return _size;
}
