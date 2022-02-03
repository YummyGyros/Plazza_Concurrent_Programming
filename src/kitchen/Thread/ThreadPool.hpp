/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ThreadPool
*/

#pragma once

#include <thread>
#include <chrono>
#include <utility>
#include <functional>

#include "Pizza.hpp"
#include "SafeQueue.hpp"
#include "Serializing.hpp"
#include "MessageQueue.hpp"
#include "PizzaDefinitions.hpp"

class ThreadPool {
    public:
        ThreadPool(float, std::size_t, SafeQueue<std::pair<PizzaType, PizzaSize>> &, MessageQueue &, int);
        ~ThreadPool();

        void cook(SafeQueue<std::pair<PizzaType, PizzaSize>> &);

    private:
        std::vector<std::thread> _threads;
        int _quantity;
        std::size_t _numberCooks;
        float _timeMultiplier;

        MessageQueue &_msg;
        int _receptionId;
        Serializing _srl;
};
