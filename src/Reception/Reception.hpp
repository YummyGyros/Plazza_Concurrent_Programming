/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <string>
#include <vector>

#include "Pizza.hpp"

class Reception {
    public:
        Reception(char **av);
        ~Reception();

        void takeOrders();

        float getTimeMultiplier() const;
        std::size_t getCooksPerKitchen() const;
        std::size_t getRestockTime() const;

    protected:
    private:
        std::vector<Pizza> parseOrder(const std::string &line);
        Pizza parsePizza(const std::string &segment);

        float _timeMultiplier;
        std::size_t _cooksPerKitchen;
        std::size_t _restockTime;
};

#endif /* !RECEPTION_HPP_ */
