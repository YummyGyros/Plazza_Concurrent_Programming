/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(const Kitchen &kitchen)
    : _timeMul(kitchen.getTimeMul()), _nbCooks(kitchen.getNbCooks()),
    _restockTime(kitchen.getRestockTime()), _totalPizze(0), _isAlive(true), _lifeTime(5),
    _msg(kitchen.getId()), _id(kitchen.getId()),
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
    SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
    ThreadPool _threads(_timeMul, _nbCooks, _queue);
}

Kitchen::Kitchen(const std::string &name, float timeMul, std::size_t nbCooks, std::size_t restockTime)
    : _timeMul(timeMul), _nbCooks(nbCooks), _restockTime(restockTime), _totalPizze(0), _isAlive(true), _lifeTime(5),
    _msg("Kitchen" + name), _id(name),
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
    SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
    ThreadPool _threads(_timeMul, _nbCooks, _queue);
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

const MessageQueue &Kitchen::getMessageQueue() const
{
    return _msg;
}

const std::string &Kitchen::getId() const
{
    return _id;
}

float Kitchen::getTimeMul() const
{
    return _timeMul;
}

const std::size_t &Kitchen::getNbCooks() const
{
    return _nbCooks;
}

const std::size_t &Kitchen::getRestockTime() const
{
    return _restockTime;
}