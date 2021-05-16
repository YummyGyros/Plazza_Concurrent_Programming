/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
**  IPizza
*/

#ifndef _IPIZZA_HPP_
#define _IPIZZA_HPP_

#include "PizzaDefinitions.hpp"

class IPizza {
    public:
        virtual ~IPizza() = default;

        virtual void setPizzaType(const PizzaType type) = 0;
        virtual void setPizzaSize(const PizzaSize size) = 0;
        virtual void setIsCooked(const bool isCooked) = 0;

        virtual PizzaType getPizzaType() const = 0;
        virtual PizzaSize getPizzaSize() const = 0;
        virtual bool getIsCooked() const = 0;
};

#endif /* !_IPIZZA_HPP_ */
