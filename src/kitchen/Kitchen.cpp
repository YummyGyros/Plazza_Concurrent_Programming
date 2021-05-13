/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(int maxCooks)
{
    _maxCooks = maxCooks;
    ThreadPool _threads();
    _isAlive = true;
    _lifeTime = 5;
    
}

Kitchen::~Kitchen()
{
}

void Kitchen::checkIsAlive()
{
    static auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >=
        std::chrono::seconds(1)) {
            _lifeTime += -1;
            start = std::chrono::steady_clock::now();
        }
    if (_lifeTime == 0)
        _isAlive = false;
}

void Kitchen::startWork()
{
    while (_isAlive) {
        checkIsAlive();
    }
}