/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

#include "Pizza.hpp"
#include "Kitchen.hpp"

class Reception {
    public:
        Reception(char **av);
        ~Reception();

        float getTimeMultiplier() const;
        std::size_t getCooksPerKitchen() const;
        std::size_t getRestockTime() const;

        const MessageQueue &getMessageQueue() const;
        void addKitchen();
        void deleteKitchen(const std::string &id);
        void restockFridges();
    protected:
    private:
        void displayOrder(const std::vector<Pizza> &pizze);
        void displayStatus();

        void updateShell();

        void manageNewOrder(const std::string &line);
        int checkLastArg(std::string &tmp);
        std::vector<Pizza> parsePizza(const std::string &segment);

        void sendPizzaToKitchen(const Pizza &pizza);
        void receiveCookedPizza();

        std::string _shellLine;

        float _timeMultiplier;
        std::size_t _cooksPerKitchen;
        std::size_t _restockTime;

        std::vector<std::vector<Pizza>> _orders;

        std::vector<Kitchen> _kitchens;
        std::size_t _kitchensId;

        MessageQueue _msg;
        std::thread _thread;
        Serializing _srl;
        std::vector<Pizza> _finishedPizze;

        bool _dogEnd;
};

#endif /* !RECEPTION_HPP_ */
