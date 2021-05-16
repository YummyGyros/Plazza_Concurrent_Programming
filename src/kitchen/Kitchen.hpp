/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#pragma once

#include <map>
#include <chrono>

#include "Pizza.hpp"
#include "SafeQueue.hpp"
#include "ThreadPool.hpp"
#include "Serializing.hpp"
#include "MessageQueue.hpp"

class Kitchen {
    public:
        Kitchen(const std::string &name, float timeMul, std::size_t nbCooks, std::size_t restockTime, int recpetionId);
        ~Kitchen();

        // GETTERS functions
        const MessageQueue &getMessageQueue() const;
        const std::string &getId() const;
        float getTimeMul() const;
        const std::size_t &getNbCooks() const;
        const std::size_t &getRestockTime() const;
        const std::size_t &getTotalPizze() const;
        const std::chrono::_V2::system_clock::time_point &getClock() const;
        const std::unordered_map<Ingredients, std::size_t> &getFridge() const;

        std::size_t calcActiveCooks() const;

        // SETTERS
        void setTotalPizze(const std::size_t &totalPizze);
        void restockFridge();
        void receiveCookedPizza();
        void takePizzaInCharge(const Pizza &pizza);

        // CHECK
        bool checkIsAlive();
        bool canCookPizza(const Pizza &pizza) const;

        // PROCESSES function
        void startWork();

    private:

        // CLOCK
        void startClock();

        std::string _id;
        MessageQueue _msg;
        Serializing _srl;
        int _receptionId;
        bool _end;

        std::chrono::_V2::system_clock::time_point _clock;
        float _timeMul;
        std::size_t _nbCooks;
        std::size_t _restockTime;
        std::size_t _totalPizze;

        bool _isAlive;

        std::thread _receive;
        std::unordered_map<Ingredients, std::size_t> _fridge;
        SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
};
