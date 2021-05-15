/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Reception
*/

#include "Reception.hpp"
#include "PizzaError.hpp"
#include <string>
#include <iostream>
#include <sstream>

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

Reception::Reception(char **av) : _shellLine(""), _msg("Reception")
{
    _timeMultiplier = std::stof(av[1]);
    _cooksPerKitchen = std::stoi(av[2]);
    _restockTime = std::stoi(av[3]);
    _kitchensId = 0;
    _thread = std::thread(&Reception::receiveCookedPizza, this);

    while (1) {
        updateShell();
        if (_shellLine.compare("") != 0) {
            if (_shellLine.compare("status") == 0)
                displayStatus();
            else if (_shellLine.compare("exit") == 0)
                break;
            else
                manageNewOrder(_shellLine);
        }
        manageOrders();
    }
}

Reception::~Reception()
{
    for (auto &order : _orders)
        order.clear();
    _orders.clear();
    _kitchens.clear();
}

void Reception::receiveCookedPizza()
{
    Pizza pizza = _srl.unpack(_msg.recvMsg<pizza_order_t>());
    bool orderReady;

    for (auto it = std::begin(_orders); it != std::end(_orders); ++it) {
        orderReady = true;
        for (auto &refPizza : *it) {
            if (!pizza.getIsCooked() && pizza == refPizza)
                refPizza.setIsCooked(true);
            if (!pizza.getIsCooked())
                orderReady = false;
        }
        if (orderReady) {
            displayOrder(*it);
            (*it).clear();
            _orders.erase(it);
            break;
        }
    }
}

float Reception::getTimeMultiplier() const
{
    return _timeMultiplier;
}

std::size_t Reception::getCooksPerKitchen() const
{
    return _cooksPerKitchen;
}

std::size_t Reception::getRestockTime() const
{
    return _restockTime;
}

void Reception::updateShell()
{
    struct timeval tv = { 0, 250000L };
    fd_set fds;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    int ready = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    if (ready < 0)
        throw Error("select failed.");
    if (ready > 0)
        std::getline(std::cin, _shellLine);
    else
        _shellLine = "";
}

void Reception::manageOrders()
{
    //_orders DISPLAY:
    // for (auto const &order : _orders)
    //     for (auto const &pizza : order)
    //         std::cout << "Pizza:\n\ttype:\t" << pizza.getPizzaType() << "\n\tsize:\t" << pizza.getPizzaSize() << std::endl;
}

// bool cmp(const Kitchen &lhs, const Kitchen &rhs)
// {
//     return lhs.getTotalPizze() < rhs.getTotalPizze();
// }

void Reception::sendPizzaToKitchen(const Pizza &pizza)
{
    // create: bool canCookPizza(PizzaType, stock)

    //ORDER RECEPTION:
    //  - find kitchen: able to craft with stock / lowest totalPizze of all
    //      --> if none can be found, create new kitchen: Kitchen("Kitchen" + _nbKitchen)
    //  - send pizza packed to kitchen
    //  - receive kitchen answer: unpack and update stocks and totalPizze in _kitchens


    // auto max = std::min_element(_kitchens.begin(), _kitchens.end(), cmp);
}

void Reception::manageNewOrder(const std::string &line)
{
    try {
        std::stringstream stream(line);
        std::string segment;
        std::vector<Pizza> pizze;

        while (std::getline(stream, segment, ';'))
            for (const auto &pizza: parsePizza(segment)) {
                sendPizzaToKitchen(pizza);
                pizze.push_back(pizza);
            }
        _orders.push_back(pizze);
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Reception::displayOrder(const std::vector<Pizza> &pizze)
{
    std::cout << "==========================" << std::endl;
    std::cout << "Order Ready" << std::endl;
    std::cout << "--------------------------" << std::endl;
    for (const auto &pizza : pizze) {
        std::cout << "pizza:\ttype:\t" << pizza.getPizzaType() << "\t\tsize:\t" << pizza.getPizzaSize() << std::endl;
    }
    std::cout << "==========================" << std::endl;
}

void Reception::displayStatus()
{
    std::cout << "Status information should be displayed here." << std::endl;
    // iterate through _kitchens
    // display stock and chiefs occupancy
}

int Reception::checkLastArg(std::string &tmp)
{
    if (tmp.length() < 2)
        return -1;
    if (tmp[0] != 'x')
        return -1;
    if (tmp[1] < '1' || tmp[1] > '9')
        return -1;
    for (int i = 1; tmp[i]; i++)
        if (tmp[i] < '0' || tmp[i] > '9')
            return -1;
    tmp.replace(0, 1, "0");
    return stod(tmp);
}

std::vector<Pizza> Reception::parsePizza(const std::string &segment)
{
    std::string tmp;
    std::stringstream stream(segment);
    Pizza pizza;
    std::vector<Pizza> pizze;
    int quantity;

    stream >> tmp;
    if (pizzaTypes.find(tmp) == pizzaTypes.end())
        throw PizzaError("size", tmp);
    pizza.setPizzaType(pizzaTypes.find(tmp)->second);

    stream >> tmp;
    if (pizzaSizes.find(tmp) == pizzaSizes.end())
        throw PizzaError("type", tmp);
    pizza.setPizzaSize(pizzaSizes.find(tmp)->second);

    stream >> tmp;
    if ((quantity = checkLastArg(tmp)) == -1)
        throw PizzaError("quantity", tmp);

    for (int i = 0; i < quantity; i++) {
        Pizza tmp(pizza);
        pizze.push_back(tmp);
    }
    return pizze;
}

const MessageQueue &Reception::getMessageQueue() const
{
    return _msg;
}

void Reception::addKitchen()
{
    _kitchensId++;
    _kitchens.emplace_back(std::to_string(_kitchensId), _timeMultiplier, _cooksPerKitchen, _restockTime, _msg.getMsgid());
}

void Reception::deleteKitchen(const std::string &id)
{
    // _kitchens.erase(std::remove_if(_kitchens.begin(), _kitchens.end(), [&id](Kitchen &kitchen){return (id == kitchen.getId());}));
}