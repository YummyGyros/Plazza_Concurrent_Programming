/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(float timeMul, std::size_t nbCooks, std::size_t restockTime)
    : _isAlive(true), _lifeTime(5), _timeMul(timeMul), _nbCooks(nbCooks), _restockTime(restockTime),
    _fridge({
        {tomato, 5},
        {gruyere, 5},
        {ham, 5},
        {mushrooms, 5},
        {steak, 5},
        {eggplant, 5},
        {goatCheese, 5},
        {chiefLove, 5}
    })
{
    ThreadPool _threads();
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