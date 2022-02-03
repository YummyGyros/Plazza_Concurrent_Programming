/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** ParseError
*/

#include "ParseError.hpp"

ParseError::ParseError(const std::string &desc) noexcept : Error("parser: " + desc)
{
}
