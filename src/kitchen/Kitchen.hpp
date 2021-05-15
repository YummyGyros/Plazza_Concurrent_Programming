/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#pragma once

#include <map>
#include <chrono>
#include <vector>

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
        void checkIsAlive();
        const MessageQueue &getMessageQueue() const;
        const std::string &getId() const;
        float getTimeMul() const;
        const std::size_t &getNbCooks() const;
        const std::size_t &getRestockTime() const;
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

        ThreadPool _threads;
        SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;

        std::map<ingredients_e, int> _fridge;
};
