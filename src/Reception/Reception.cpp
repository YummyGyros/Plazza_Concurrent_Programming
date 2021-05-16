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
    displayString("############## Welcome to the Pizzeria Piazza ##############");

    while (1) {
        start = restockClock(start);
        deleteKitchen();
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

void Reception::deleteKitchen()
{
    auto time = std::chrono::high_resolution_clock::now();

    for (auto kitchen : _kitchens) {
        if (kitchen->getTotalPizze() != 0)
            kitchen->startClock();
        else if (std::chrono::duration_cast<std::chrono::milliseconds>(kitchen->getClock() - time).count() > 5)
            _kitchens.erase(std::find(_kitchens.begin(), _kitchens.end(), kitchen));
    }
}

void Reception::displayString(const std::string &str)
{
    std::cout << str << std::endl;
    _logfile << str << std::endl;
}

void Reception::displayOrder(const std::vector<std::shared_ptr<Pizza>> &pizze)
{
    displayString("==========================");
    displayString("Order Ready");
    displayString("--------------------------");
    for (const auto &pizza : pizze)
        displayString("\tpizza:\ttype:\t" + pizza->getTypeStr() + "\t\tsize:\t" + pizza->getSizeStr());
    displayString("       Buon Appetito      ");
    displayString("==========================");
}

void Reception::displayStatus()
{
    if (_kitchens.empty())
        displayString("No kitchen exist at this time.");
    else
        displayString("=========Status===========");
    for (const auto &kitchen : _kitchens) {
        auto fridge = kitchen->getFridge();
        displayString("kitchen " + kitchen->getId() + ":");
        displayString("\tpizze in charge: " + kitchen->calcActiveCooks());
        displayString ("active cooks: " + std::to_string(kitchen->calcActiveCooks()));
        for (auto ingredient : fridge)
            displayString("\t" + ingredientsToString.find(ingredient.first)->second + ":" + std::to_string(ingredient.second));
        displayString("==========================");
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
        std::vector<std::shared_ptr<Pizza>> pizze;

        while (std::getline(stream, segment, ';'))
            for (const auto &pizza: parsePizza(segment))
                pizze.push_back(pizza);
        for (const auto &pizza : pizze)
            sendPizzaToKitchen(*pizza);
        _orders.push_back(pizze);
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::vector<std::shared_ptr<Pizza>> Reception::parsePizza(const std::string &segment)
{
    std::stringstream stream(segment);
    std::string tmp;
    std::string size;
    std::string type;
    std::vector<std::shared_ptr<Pizza>> pizze;
    int quantity;

    stream >> type;
    std::for_each(type.begin(), type.end(), [](char &c) {
        c = ::tolower(c);
    });
    stream >> size;
    stream >> tmp;
    quantity = checkLastArg(tmp);
    if (quantity == -1)
        throw PizzaError("quantity", tmp);

    for (int i = 0; i < quantity; i++)
        pizze.emplace_back(std::make_unique<Pizza>(type, size));
    return pizze;
}

bool cmpTotalPizze(const std::shared_ptr<Kitchen> &lhs, const std::shared_ptr<Kitchen> &rhs)
{
    return lhs->getTotalPizze() < rhs->getTotalPizze();
}

void Reception::sendPizzaToKitchen(const Pizza &pizza)
{
    std::vector<std::shared_ptr<Kitchen>> kitchensCanCook;
    std::shared_ptr<Kitchen> ptrKitchen;

    for (const auto &kitchen : _kitchens)
        if (kitchen->canCookPizza(pizza))
            kitchensCanCook.emplace_back(kitchen);

    if (kitchensCanCook.empty()) {
        ptrKitchen = std::make_shared<Kitchen>(std::to_string(++_kitchensId), _timeMultiplier, _cooksPerKitchen, _restockTime, _msg.getMsgid());
        Processes p(*ptrKitchen);
        _kitchens.push_back(ptrKitchen);
    } else
        ptrKitchen = *std::min_element(kitchensCanCook.begin(), kitchensCanCook.end(), cmpTotalPizze);
    for (const auto &kitchen : _kitchens)
        if (kitchen->getId().compare(ptrKitchen->getId()) == 0) {
            kitchen->takePizzaInCharge(pizza);
            _msg.sendMsg<pizza_order_t>(_srl.pack(pizza, _msg.getMsgid()), kitchen->getMessageQueue().getMsgid());
            displayString("[sent]: " + pizza.getTypeStr() + " size " + pizza.getSizeStr() + " to Kitchen" + kitchen->getId());
        }
}

void Reception::receiveCookedPizza()
{
    while (_end) {
        try {
            pizza_order_t pizzaMsg = _srl.unpack(_msg.recvMsg<pizza_order_t>());
            bool orderReady;

            for (auto &kitchen : _kitchens) {
                if (kitchen->getMessageQueue().getMsgid() == pizzaMsg.id)
                    kitchen->setTotalPizze(kitchen->getTotalPizze() - 1);
            }

            for (auto it = std::begin(_orders); it != std::end(_orders); ++it) {
                orderReady = true;
                for (auto &refPizza : *it) {
                    if (!refPizza->getIsCooked() && pizzaMsg.size == refPizza->getSize() && pizzaMsg.type == refPizza->getType())
                        refPizza->setIsCooked(true);
                    if (!refPizza->getIsCooked())
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

    if (timer.count() >= (int64_t)_restockTime) {
        for (auto &kitchen : _kitchens)
            kitchen->restockFridge();
        start = std::chrono::high_resolution_clock::now();
    }
    return start;
}