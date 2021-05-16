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
#include <utility>

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

Reception::Reception(char **av, const std::string &pathLogfile)
    : _shellLine(""),
    _kitchensId(0),
    _timeMultiplier(std::stof(av[1])),
    _cooksPerKitchen(std::stoi(av[2])),
    _restockTime(std::stoi(av[3])),
    _msg("Reception"),
    _thread(std::thread(&Reception::receiveCookedPizza, this)),
    _pathLogfile(pathLogfile),
    _end(true)
{
    auto start = std::chrono::high_resolution_clock::now();
    _logfile.open(_pathLogfile);
    std::cout <<"############## Welcome to the Pizzeria Piazza ##############" << std::endl;

    while (1) {
        start = restockClock(start);
        updateShell();
        if (_shellLine.compare("") != 0) {
            if (_shellLine.compare("status") == 0)
                displayStatus();
            else if (_shellLine.compare("exit") == 0) {
                _end = false;
                break;
            } else
                manageNewOrder(_shellLine);
        }
    }
}

Reception::~Reception()
{
    _thread.join();
    for (auto &order : _orders)
        order.clear();
    _orders.clear();
    _kitchens.clear();
    _logfile.close();
}

void Reception::displayOrder(const std::vector<Pizza> &pizze)
{
    std::cout <<"==========================" << std::endl;
    std::cout <<"Order Ready" << std::endl;
    std::cout <<"--------------------------" << std::endl;
    for (const auto &pizza : pizze) {
        std::cout <<"\tpizza:\ttype:\t" << pizzaTypesToString.find(pizza.getType())->first
        << "\t\tsize:\t" << pizzaSizesToString.find(pizza.getSize())->first << std::endl;
    }
    std::cout <<"       Buon Appetito      " << std::endl;
    std::cout <<"==========================" << std::endl;
}

void Reception::displayStatus()
{
    if (_kitchens.empty())
        std::cout <<"No kitchen exist at this time." << std::endl;
    else
        std::cout <<"=========Status===========" << std::endl;
    for (const auto &kitchen : _kitchens) {
        auto fridge = kitchen.getFridge();
        std::cout <<kitchen.getId() << ":" << std::endl;
        std::cout <<"\tpizze in charge: "<< kitchen.getTotalPizze() << std::endl;
        for (auto ingredient : fridge)
            std::cout <<"\t" << ingredient.first << ":\t" << ingredient.second << std::endl;
        std::cout <<"==========================" << std::endl;
    }
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

void Reception::manageNewOrder(const std::string &line)
{
    try {
        std::stringstream stream(line);
        std::string segment;
        std::vector<Pizza> pizze;

        while (std::getline(stream, segment, ';'))
            for (const auto &pizza: parsePizza(segment))
                pizze.push_back(pizza);
        for (const auto &pizza : pizze)
            sendPizzaToKitchen(pizza);
        _orders.push_back(pizze);
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

// std::vector<Pizza> Reception::parsePizza(const std::string &segment)
// {
//     std::string tmp;
//     std::stringstream stream(segment);
//     Pizza pizza;
//     std::vector<Pizza> pizze;
//     int quantity;

//     stream >> tmp;
//     if (pizzaTypes.find(tmp) == pizzaTypes.end())
//         throw PizzaError("size", tmp);
//     pizza.setPizzaType(pizzaTypes.find(tmp)->second);

//     stream >> tmp;
//     if (pizzaSizes.find(tmp) == pizzaSizes.end())
//         throw PizzaError("type", tmp);
//     pizza.setPizzaSize(pizzaSizes.find(tmp)->second);

//     stream >> tmp;
//     if ((quantity = checkLastArg(tmp)) == -1)
//         throw PizzaError("quantity", tmp);

//     for (int i = 0; i < quantity; i++) {
//         Pizza tmp(pizza);
//         pizze.push_back(tmp);
//     }
//     return pizze;
// }

std::vector<Pizza> Reception::parsePizza(const std::string &segment)
{
    std::stringstream stream(segment);
    std::string tmp;
    std::string size;
    std::string type;
    std::vector<Pizza> pizze;
    int quantity;

    stream >> type;
    stream >> size;
    stream >> tmp;
    quantity = checkLastArg(tmp);
    if (quantity == -1)
        throw PizzaError("quantity", tmp);

    for (int i = 0; i < quantity; i++) {
        Pizza tmp(type, size);
        pizze.push_back(tmp);
    }
    return pizze;
}

bool cmpTotalPizze(const Kitchen &lhs, const Kitchen &rhs)
{
    return lhs.getTotalPizze() < rhs.getTotalPizze();
}

void Reception::sendPizzaToKitchen(const Pizza &pizza)
{
    std::vector<Kitchen> kitchensCanCook;

    for (const auto kitchen : _kitchens)
        if (kitchen.canCookPizza(pizza))
            kitchensCanCook.push_back(kitchen);

    if (kitchensCanCook.empty()) {
        Kitchen k(std::to_string(++_kitchensId), _timeMultiplier, _cooksPerKitchen, _restockTime, _msg.getMsgid());
        Processes p(k);
        _kitchens.push_back(k);
    }
    else {
        Kitchen k(*std::min_element(kitchensCanCook.begin(), kitchensCanCook.end(), cmpTotalPizze));
        Processes p(k);
        _kitchens.push_back(k);
    }
    _kitchens.at(_kitchens.size() - 1).takePizzaInCharge(pizza);
    _msg.sendMsg<pizza_order_t>(_srl.pack(pizza), _kitchens.at(_kitchens.size() - 1).getMessageQueue().getMsgid());
    std::cout <<"Order: pizza " << pizzaTypesToString.find(pizza.getType())->second << " size "
    << pizzaSizesToString.find(pizza.getSize())->second << " sent to the kitchen." << std::endl;
}

void Reception::receiveCookedPizza()
{
    while (_end) {
        try {
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
        } catch (CommunicationError &e) {
        }
    }
}

std::chrono::_V2::system_clock::time_point Reception::restockClock(std::chrono::_V2::system_clock::time_point start)
{
    const auto temp = std::chrono::high_resolution_clock::now();
    auto timer = std::chrono::duration_cast<std::chrono::milliseconds>(temp - start);

    if (timer.count() >= _restockTime) {
        for (auto &kitchen : _kitchens)
            kitchen.restockFridge();
        start = std::chrono::high_resolution_clock::now();
    }
    return start;
}