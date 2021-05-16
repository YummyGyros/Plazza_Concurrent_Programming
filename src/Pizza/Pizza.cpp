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

Pizza::~Pizza()
{
}

Pizza::Pizza(PizzaType type, PizzaSize size) :_type(type), _size(size)
{
}

Pizza::Pizza(const Pizza &pizza)
{
    this->_size = pizza._size;
    this->_type = pizza._type;
}

bool Pizza::operator==(const Pizza &rhs) const
{
    return _type == rhs._type && _size == rhs._size;
}

void Pizza::setPizzaType(const PizzaType type)
{
    _type = type;
}

void Pizza::setIsCooked(const bool isCooked)
{
    _isCooked = isCooked;
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

bool Pizza::getIsCooked() const
{
    return _isCooked;
}