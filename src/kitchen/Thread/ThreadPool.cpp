/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

void ThreadPool::cook(SafeQueue<std::pair<PizzaType, PizzaSize>> &queue)
{
    std::pair<PizzaType, PizzaSize> pizza;

    while (true) {
        pizza = queue.pop();
        std::this_thread::sleep_for((std::chrono::milliseconds) (int)(_timeMultiplier * timeToCook.at(pizza.first)));
        //send message
    }
}

ThreadPool::ThreadPool(float timeMult, std::size_t numberCooks, SafeQueue<std::pair<PizzaType, PizzaSize>> &queue)
    : _timeMultiplier(timeMult), _numberCooks(numberCooks)
{
    int n = 0;

    while (n != _numberCooks) {
        _threads.push_back(std::thread(&ThreadPool::cook, this, std::ref(queue)));
        n++;
    }
    n = 0;
    while (n != _numberCooks) {
        _threads.at(n).join();
        n++;
    }
}

ThreadPool::~ThreadPool()
{
    _threads.clear();
}
