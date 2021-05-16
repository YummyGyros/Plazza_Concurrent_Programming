/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(const std::string &name, float timeMul, std::size_t nbCooks, std::size_t restockTime, int receptionId)
    : _id(name), _msg("Kitchen" + name),  _receptionId(receptionId),  _end(true), _timeMul(timeMul), _nbCooks(nbCooks), _restockTime(restockTime), _totalPizze(0), _isAlive(true),
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
}

Kitchen::~Kitchen()
{
}

void Kitchen::receiveCookedPizza()
{
    while (_end) {
        try {
            pizza_order_t pizzaMsg = _srl.unpack(_msg.recvMsg<pizza_order_t>());
            _queue.push(std::make_pair(pizzaMsg.type, pizzaMsg.size));
        } catch (CommunicationError &e) {
        }
    }
}

bool Kitchen::canCookPizza(const Pizza &pizza) const
{
    if (_totalPizze >= _nbCooks * 2)
        return false;
    for (Ingredients ingr: pizza.getRecipe()) {
        if (_fridge.find(ingr)->second == 0)
            return false;
    }
    return true;
}

void Kitchen::takePizzaInCharge(const Pizza &pizza)
{
    for (Ingredients ingr: pizza.getRecipe())
        _fridge[ingr] -= 1;
    _totalPizze++;
}

bool Kitchen::checkIsAlive()
{
    return _isAlive;
}

void Kitchen::startWork()
{

    ThreadPool threads(_timeMul, _nbCooks, _queue, _msg, _receptionId);
    _receive = std::thread(&Kitchen::receiveCookedPizza, this);

    while (_isAlive) {
        auto time = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(_clock - time).count() > 5)
            _isAlive = false;
    }
    std::exit(0);
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

const std::size_t &Kitchen::getTotalPizze() const
{
    return _totalPizze;
}

void Kitchen::setTotalPizze(const std::size_t &totalPizze)
{
    _totalPizze = totalPizze;
}

void Kitchen::restockFridge()
{
    for (auto &ingr : _fridge)
        if (ingr.second < 5)
            ingr.second++;
}

const std::unordered_map<Ingredients, std::size_t> &Kitchen::getFridge() const
{
    return _fridge;
}

std::size_t Kitchen::calcActiveCooks() const
{
    return _totalPizze > _nbCooks ? _totalPizze - _nbCooks : _totalPizze;
}

void Kitchen::startClock()
{
    _clock = std::chrono::high_resolution_clock::now();
}

const std::chrono::_V2::system_clock::time_point &Kitchen::getClock() const
{
    return _clock;
}