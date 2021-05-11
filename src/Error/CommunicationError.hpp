/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** CommunicationError
*/

#ifndef COMMUNICATIONERROR_HPP_
#define COMMUNICATIONERROR_HPP_

#include "Error.hpp"

class CommunicationError : public Error {
    public:
        CommunicationError(const std::string &desc) noexcept;
        ~CommunicationError() = default;

    protected:
    private:
};

#endif /* !COMMUNICATIONERROR_HPP_ */
