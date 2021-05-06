/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** Mutex
*/

#include "Mutex.hpp"

void Mutex::lock()
{
    pthread_mutex_lock(&_mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&_mutex);
}

void Mutex::trylock()
{
    pthread_mutex_trylock(&_mutex);
}

pthread_mutex_t Mutex::getMutex()
{
    return (_mutex);
}