/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include " IPizza.hpp"
#include "PizzaDefinitions.hpp"
#include <string>
#include <map>

class Pizza : public IPizza {
    public:
        Pizza();
        ~Pizza() override;
        Pizza(PizzaType _type, PizzaSize _size);
        Pizza(const Pizza &pizza);
        bool operator==(const Pizza &rhs) const;

        void setPizzaType(const PizzaType type) override;
        void setPizzaSize(const PizzaSize size) override;
        void setIsCooked(const bool isCooked) override;

        PizzaType getPizzaType() const override;
        PizzaSize getPizzaSize() const override;
        bool getIsCooked() const override;
    protected:
    private:
        PizzaType _type;
        PizzaSize _size;
        bool _isCooked;
};

#endif /* !PIZZA_HPP_ */
