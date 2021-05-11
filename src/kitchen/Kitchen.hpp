/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#pragma once

#include "ThreadPool.hpp"
#include <map>
#include <chrono>

class Kitchen {
    public:
        Kitchen(int);
        ~Kitchen();

        void startWork();
        void checkIsAlive();

    private:
        ThreadPool _threads;
        bool _isAlive;
        int _lifeTime;
        int _maxCooks;
};
