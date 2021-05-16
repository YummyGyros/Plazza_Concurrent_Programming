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

        void startWork();
        void checkIsAlive();

        bool canCookPizza(const Pizza &pizza) const;
        void takePizzaInCharge(const Pizza &pizza);

        const MessageQueue &getMessageQueue() const;
        const std::string &getId() const;
        float getTimeMul() const;
        const std::size_t &getNbCooks() const;
        const std::size_t &getRestockTime() const;
        const std::size_t &getTotalPizze() const;
        void setTotalPizze(const std::size_t &totalPizze);

        void restockFridge();
        void receiveCookedPizza();
        const std::unordered_map<Ingredients, std::size_t> &getFridge() const;

        std::size_t calcActiveCooks() const;

    private:
        std::string _id;
        MessageQueue _msg;
        Serializing _srl;
        int _receptionId;
        bool _end;

        float _timeMul;
        std::size_t _nbCooks;
        std::size_t _restockTime;
        std::size_t _totalPizze;

        bool _isAlive;
        int _lifeTime;

        std::thread _receive;
        std::unordered_map<Ingredients, std::size_t> _fridge;
        SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
};
