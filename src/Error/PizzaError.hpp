/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** PizzaError
*/

#ifndef PIZZAERROR_HPP_
#define PIZZAERROR_HPP_

#include "ParseError.hpp"

class PizzaError : public ParseError {
    public:
        PizzaError(const std::string &type, const std::string &desc) noexcept;
        ~PizzaError() = default;

    protected:
    private:
};

#endif /* !PIZZAERROR_HPP_ */
