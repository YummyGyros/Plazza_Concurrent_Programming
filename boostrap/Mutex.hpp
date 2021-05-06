/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** Mutex
*/

#pragma once

#include "AMutex.hpp"
#include "pthread.h"

class Mutex : public AMutex{
    public:
        Mutex() = default;
        ~Mutex() = default;

        void lock();
        void unlock();
        void trylock();
        pthread_mutex_t getMutex();

    private:
        pthread_mutex_t _mutex;
};
