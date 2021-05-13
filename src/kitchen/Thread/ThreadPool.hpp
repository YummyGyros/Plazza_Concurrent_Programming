/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ThreadPool
*/

#pragma once

#include <thread>
#include <vector>
#include <chrono>
#include <utility>
#include <functional>

#include "SafeQueue.hpp"
#include "PizzaDefinitions.hpp"

static const std::map<PizzaType, float> timeToCook = { 
    {Margarita, {1000}},
    {Regina, {2000}},
    {Americana, {2000}},
    {Fantasia, {4000}}
};

class ThreadPool {
    public:
        ThreadPool() = default;
        ThreadPool(float, std::size_t, SafeQueue<std::pair<PizzaType, PizzaSize>> &);
        ~ThreadPool();

        void cook(SafeQueue<std::pair<PizzaType, PizzaSize>> &);

    private:
        std::vector<std::thread> _threads;
        int _quantity;
        std::size_t _numberCooks;
        float _timeMultiplier;
};
