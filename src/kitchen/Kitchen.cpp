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
    _msg(std::move(kitchen._id)), _id(std::move(kitchen._id)), _receptionId(kitchen._receptionId), _end(true),
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
    : _timeMul(timeMul), _nbCooks(nbCooks), _restockTime(restockTime), _totalPizze(0), _isAlive(true), _lifeTime(5), _end(true),
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

void Kitchen::receiveCookedPizza()
{
    while (_end) {
        try {
            Pizza pizza = _srl.unpack(_msg.recvMsg<pizza_order_t>());
            _queue.push(std::make_pair(pizza.getType(), pizza.getSize()));
        } catch (CommunicationError &e) {
        }
    }
}

bool Kitchen::canCookPizza(const Pizza &pizza) const
{
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

void Kitchen::checkIsAlive(ThreadPool &threads)
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

    SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
    ThreadPool threads(_timeMul, _nbCooks, _queue, _msg, _receptionId);
    _receive = std::thread(&Kitchen::receiveCookedPizza, this);

    while (_isAlive) {
        //checkIsAlive(threads);
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

void Kitchen::restockFridge()
{
    for (auto &ingr : _fridge)
        ingr.second++;
}

const std::unordered_map<Ingredients, std::size_t> &Kitchen::getFridge() const
{
    return _fridge;
}