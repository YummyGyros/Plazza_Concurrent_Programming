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

        virtual PizzaType getType() const = 0;
        virtual PizzaSize getSize() const = 0;
        virtual const std::string &getTypeStr() const = 0;
        virtual const std::string &getSizeStr() const = 0;
        virtual const std::vector<Ingredients> &getRecipe() const = 0;

        virtual bool getIsCooked() const = 0;
        virtual void setIsCooked(const bool isCooked) = 0;
};

#endif /* !_IPIZZA_HPP_ */
