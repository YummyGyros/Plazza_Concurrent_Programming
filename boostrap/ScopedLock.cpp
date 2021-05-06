/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex temp)
{
    _temp = temp;
    _temp.lock();
}

ScopedLock::~ScopedLock()
{
    _temp.unlock();
}
