/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include "PizzaDefinitions.hpp"
#include <string>
#include <map>

class Pizza {
    public:
        Pizza();
        Pizza(const Pizza &pizza);
        ~Pizza() = default;

        void setPizzaType(const PizzaType type);
        void setPizzaSize(const PizzaSize size);

        PizzaType getPizzaType() const;
        PizzaSize getPizzaSize() const;
    protected:
    private:
        PizzaType _type;
        PizzaSize _size;
};

#endif /* !PIZZA_HPP_ */
