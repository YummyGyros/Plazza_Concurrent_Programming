/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ProcessesError
*/

#pragma once

#include "Error.hpp"

class ProcessesError : public Error {
    public:
        ProcessesError(const std::string &desc) noexcept;
        ~ProcessesError() = default;

    protected:
    private:
};
