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
#include <ratio>
#include <fstream>

#include "Pizza.hpp"
#include "Kitchen.hpp"
#include "Processes.hpp"

class Reception {
    public:
        Reception(char **av, const std::string &pathLogfile);
        ~Reception();
    private:
        // DISPLAY Functions
        void displayOrder(const std::vector<Pizza> &pizze);
        void displayStatus();

        // PARSING Functions
        int checkLastArg(std::string &tmp);
        void updateShell();
        void manageNewOrder(const std::string &line);
        std::vector<Pizza> parsePizza(const std::string &segment);

        // IPC Functions
        void sendPizzaToKitchen(const Pizza &pizza);
        void receiveCookedPizza();
    
        // KITCHENS Functions
        std::chrono::_V2::system_clock::time_point restockClock
        (std::chrono::_V2::system_clock::time_point);

        // PARSING Variables
        std::string _shellLine;

        // ARGS Variables
        float _timeMultiplier;
        std::size_t _cooksPerKitchen;
        std::size_t _restockTime;

        // KITCHENS Variables
        std::vector<Kitchen> _kitchens;
        std::vector<std::vector<Pizza>> _orders;
        std::size_t _kitchensId;

        // IPC Variables
        MessageQueue _msg;
        std::thread _thread;
        Serializing _srl;

        // DISPLAY Variables
        std::string _pathLogfile;
        std::ofstream _logfile;

        // LOOP HANDLING Variables
        bool _end;
};

#endif /* !RECEPTION_HPP_ */
