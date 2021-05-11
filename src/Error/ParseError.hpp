/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** ParseError
*/

#ifndef PARSEERROR_HPP_
#define PARSEERROR_HPP_

#include "Error.hpp"

class ParseError : public Error {
    public:
        ParseError(const std::string &desc) noexcept;
        ~ParseError() = default;

    protected:
    private:
};

#endif /* !PARSEERROR_HPP_ */
