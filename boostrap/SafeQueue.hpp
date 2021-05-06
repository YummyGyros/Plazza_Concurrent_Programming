/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** SafeQueue
*/

#pragma once

#include "ASafeQueue.hpp"
#include <chrono>
#include <thread>

template <class T>
class SafeQueue : public ASafeQueue {
    public:
        SafeQueue();
        ~SafeQueue();

        void push(T value);
        bool tryPop(T &value);
        T pop();

    protected:
    private:
};
