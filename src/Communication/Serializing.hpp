/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** Serializing
*/

#ifndef SERIALIZING_HPP_
#define SERIALIZING_HPP_

#include "MessageQueue.hpp"

class Serializing {
    public:
        Serializing();
        ~Serializing();

        pizza_order_t pack(const Pizza &pizza, int myid);
        status_t pack(std::unordered_map<Ingredients, std::size_t> stock);

        pizza_order_t unpack(pizza_order_t pizza);
        std::unordered_map<Ingredients, std::size_t> unpack(status_t stock);

    protected:
    private:
};

#endif /* !SERIALIZING_HPP_ */
