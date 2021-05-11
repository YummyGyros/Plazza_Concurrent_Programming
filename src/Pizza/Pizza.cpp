/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Pizza
*/

#include "Pizza.hpp"

Pizza::Pizza()
{
}

Pizza::Pizza(const Pizza &pizza)
{
    this->_size = pizza._size;
    this->_type = pizza._type;
}

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
