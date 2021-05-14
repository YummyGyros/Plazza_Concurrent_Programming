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

#include "Pizza.hpp"
#include "Kitchen.hpp"

class Reception {
    public:
        Reception(char **av);
        ~Reception();

        void selectStdin();

        float getTimeMultiplier() const;
        std::size_t getCooksPerKitchen() const;
        std::size_t getRestockTime() const;

        const MessageQueue &getMessageQueue() const;
        void addKitchen();
        void deleteKitchen(const std::string &id);
    protected:
    private:

        void displayStatus();
        void manageOrders();
        void updateShell();
        int checkLastArg(std::string &tmp);

        void getNewOrder(const std::string &line);
        std::vector<Pizza> parsePizza(const std::string &segment);
        void takeFinishedOrders();

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
};

#endif /* !RECEPTION_HPP_ */
