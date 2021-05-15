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
        Kitchen(const Kitchen &kitchen);
        ~Kitchen();

        void startWork();
        void checkIsAlive(ThreadPool &);
        bool canCookPizza(const Pizza &pizza) const;
        void consumeIngredientsForPizza(const Pizza &pizza);
        const MessageQueue &getMessageQueue() const;
        const std::string &getId() const;
        float getTimeMul() const;
        const std::size_t &getNbCooks() const;
        const std::size_t &getRestockTime() const;
        const std::size_t &getTotalPizze() const;
        const std::unordered_map<ingredients_e, std::size_t> &getFridge() const {
            return _fridge;
        };
        void setFridge(const std::unordered_map<ingredients_e, std::size_t> &fridge) {
            _fridge = fridge;
        };
        void takeOrders();

    private:
        std::string _id;
        MessageQueue _msg;
        Serializing _srl;
        int _receptionId;
        std::thread _orders;

        float _timeMul;
        std::size_t _nbCooks;
        std::size_t _restockTime;
        std::size_t _totalPizze;

        bool _isAlive;
        int _lifeTime;

        std::unordered_map<ingredients_e, std::size_t> _fridge;
        SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
};
