/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ProcessesError
*/

#include "ProcessesError.hpp"

ProcessesError::ProcessesError(const std::string &desc) noexcept : Error("Processes: " + desc)
{
}

ProcessesError::~ProcessesError()
{
}