/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Pizza
*/

#include "Pizza.hpp"

PizzaType Pizza::getPizzaType() const
{
    return _type;
}

PizzaSize Pizza::getPizzaSize() const
{
    return _size;
}