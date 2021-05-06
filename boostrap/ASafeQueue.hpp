/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ASafeQueue
*/

#pragma once

#include "ISafeQueue.hpp"
#include <queue>

class ASafeQueue : public ISafeQueue{
    public:
        ASafeQueue() = default;
        ~ASafeQueue() = default;

    protected:
        std::queue<int> _queue;
};