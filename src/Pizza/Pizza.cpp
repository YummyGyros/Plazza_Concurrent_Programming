/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Pizza
*/

#include "Pizza.hpp"
#include "PizzaError.hpp"

Pizza::~Pizza()
{
}

Pizza::Pizza(PizzaType type, PizzaSize size) noexcept
    : _typeStr(pizzaTypesToString.find(type)->second),
    _type(type),
    _sizeStr(pizzaSizesToString.find(size)->second),
    _size(size),
    _recipe(recipes.find(type)->second),
    _isCooked(false)
{
}

Pizza::Pizza(const std::string &type, const std::string &size)
    : _typeStr(type), _sizeStr(size), _isCooked(false)
{
    if (pizzaTypes.find(type) == pizzaTypes.end())
        throw PizzaError("type", type);
    _type = pizzaTypes.find(type)->second;
    _recipe = recipes.find(_type)->second;

    if (pizzaSizes.find(size) == pizzaSizes.end())
        throw PizzaError("size", size);
    _size = pizzaSizes.find(size)->second;
}

bool Pizza::operator==(const Pizza &rhs) const
{
    return _type == rhs._type && _size == rhs._size;
}

PizzaType Pizza::getType() const
{
    return _type;
}

PizzaSize Pizza::getSize() const
{
    return _size;
}

const std::string &Pizza::getTypeStr() const
{
    return _typeStr;
}

const std::string &Pizza::getSizeStr() const
{
    return _sizeStr;
}

const std::vector<Ingredients> &Pizza::getRecipe() const
{
    return _recipe;
}

bool Pizza::getIsCooked() const
{
    return _isCooked;
}

void Pizza::setIsCooked(const bool isCooked)
{
    _isCooked = isCooked;
}