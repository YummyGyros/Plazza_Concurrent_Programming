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
        bool operator==(const Pizza &rhs) const;

        void setPizzaType(const PizzaType type);
        void setPizzaSize(const PizzaSize size);
        void setIsCooked(const bool isCooked);

        PizzaType getPizzaType() const;
        PizzaSize getPizzaSize() const;
        bool getIsCooked() const;
    protected:
    private:
        PizzaType _type;
        PizzaSize _size;
        bool _isCooked;
};

#endif /* !PIZZA_HPP_ */
