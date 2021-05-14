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

#include "SafeQueue.hpp"
#include "ThreadPool.hpp"
#include "PizzaDefinitions.hpp"
#include "MessageQueue.hpp"
#include "Serializing.hpp"

class Kitchen {
    public:
        Kitchen(const std::string &name, float timeMul, std::size_t nbCooks, std::size_t restockTime);
        Kitchen(const Kitchen &kitchen);
        ~Kitchen();

        void startWork();
        void checkIsAlive();
        const MessageQueue &getMessageQueue() const;
        const std::string &getId() const;
        float getTimeMul() const;
        const std::size_t &getNbCooks() const;
        const std::size_t &getRestockTime() const;

    private:
        std::string _id;
        MessageQueue _msg;
        Serializing srl;

        float _timeMul;
        std::size_t _nbCooks;
        std::size_t _restockTime;

        std::size_t _totalPizze;
        bool _isAlive;
        int _lifeTime;

        ThreadPool _threads;
        std::map<ingredients_e, std::size_t> _fridge;

        SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
};
