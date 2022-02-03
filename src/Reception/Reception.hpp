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
#include <memory>
#include <list>

#include "Pizza.hpp"
#include "Kitchen.hpp"
#include "Processes.hpp"

class Reception {
    public:
        Reception(char **av, const std::string &pathLogfile);
        ~Reception();
    private:
        // DISPLAY Functions
        void displayString(const std::string &str);
        void displayOrder(const std::vector<std::shared_ptr<Pizza>> &pizze);
        void displayStatus();

        // PARSING Functions
        int checkLastArg(std::string &tmp);
        void updateShell();
        void manageNewOrder(const std::string &line);
        std::vector<std::shared_ptr<Pizza>> parsePizza(const std::string &segment);

        // IPC Functions
        void sendPizzaToKitchen(const Pizza &pizza);
        void receiveCookedPizza();
    
        // KITCHENS Functions
        std::chrono::_V2::system_clock::time_point restockClock
        (std::chrono::_V2::system_clock::time_point);
        bool deleteKitchen(pizza_order_t);

        // PARSING Variables
        std::string _shellLine;

        // KITCHENS Variables
        std::list<std::shared_ptr<Kitchen>> _kitchens;
        std::vector<std::vector<std::shared_ptr<Pizza>>> _orders;
        std::size_t _kitchensId;
        float _timeMultiplier;
        std::size_t _cooksPerKitchen;
        std::size_t _restockTime;

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
