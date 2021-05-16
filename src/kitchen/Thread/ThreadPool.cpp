/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

ThreadPool::~ThreadPool()
{
    _threads.clear();
}

void ThreadPool::cook(SafeQueue<std::pair<PizzaType, PizzaSize>> &queue)
{
    std::pair<PizzaType, PizzaSize> pizza;

    while (true) {
        pizza = queue.pop();
        std::this_thread::sleep_for((std::chrono::milliseconds) (int)(_timeMultiplier * timeToCook.at(pizza.first)));
        _msg.sendMsg<pizza_order_t>(_srl.pack(Pizza(pizza.first, pizza.second), _msg.getMsgid()), _receptionId);
    }
}

ThreadPool::ThreadPool(float timeMult, std::size_t numberCooks, SafeQueue<std::pair<PizzaType, PizzaSize>> &queue, MessageQueue id, int rid)
    : _timeMultiplier(timeMult), _numberCooks(numberCooks), _receptionId(rid), _msg(id.getFile())
{
    int n = 0;

    while (n != _numberCooks) {
        _threads.push_back(std::move(std::thread(&ThreadPool::cook, this, std::ref(queue))));
        n++;
    }
}
