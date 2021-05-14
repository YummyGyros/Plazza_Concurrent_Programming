/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(const Kitchen &kitchen)
    : _timeMul(std::move(kitchen._timeMul)), _nbCooks(std::move(kitchen._nbCooks)),
    _restockTime(std::move(kitchen._restockTime)), _totalPizze(0), _isAlive(true), _lifeTime(5),
    _msg(std::move(kitchen._id)), _id(std::move(kitchen._id)), _receptionId(kitchen._receptionId),
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
}

Kitchen::Kitchen(const std::string &name, float timeMul, std::size_t nbCooks, std::size_t restockTime, int receptionId)
    : _timeMul(timeMul), _nbCooks(nbCooks), _restockTime(restockTime), _totalPizze(0), _isAlive(true), _lifeTime(5),
    _msg("Kitchen" + name), _id(name), _receptionId(receptionId),
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

void Kitchen::takeOrders()
{
    while (true) {
        Pizza pizza = _srl.unpack(_msg.recvMsg<pizza_order_t>());
        _queue.push(std::make_pair(pizza.getPizzaType(), pizza.getPizzaSize()));
    }
}

void Kitchen::startWork()
{
    SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
    ThreadPool _threads(_timeMul, _nbCooks, _queue);
    _orders = std::thread(&Kitchen::takeOrders);

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