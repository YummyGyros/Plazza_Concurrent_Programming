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
#include "Kitchen.hpp"

class Reception {
    public:
        Reception(char **av);
        ~Reception();

        void start();
        void displayStatus();

        float getTimeMultiplier() const;
        std::size_t getCooksPerKitchen() const;
        std::size_t getRestockTime() const;

    protected:
    private:
        int checkLastArg(std::string &tmp);

        void manageOrder(const std::string &line);
        std::vector<Pizza> parseOrder(const std::string &line);
        std::vector<Pizza> parsePizza(const std::string &segment);

        float _timeMultiplier;
        std::size_t _cooksPerKitchen;
        std::size_t _restockTime;
        std::vector<Kitchen> _kitchens;
};

#endif /* !RECEPTION_HPP_ */
