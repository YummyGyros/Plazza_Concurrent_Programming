/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** SafeQueue
*/

#pragma once

#include <queue>
#include <mutex>
#include <chrono>
#include <condition_variable>

#include <iostream>

template <class T>
class SafeQueue {
    public:
        SafeQueue() = default;
        ~SafeQueue() = default;

        void push(T value)
        {
            std::unique_lock<std::mutex> lock(_mutexQueue, std::defer_lock);
            _queue.push(value);
            _mutexQueue.unlock();
            _cv.notify_all();
        };

        T pop()
        {
            T value;

            std::unique_lock<std::mutex> lock(_mutexQueue);
            _cv.wait(lock, [&]{ return tryPop(value); });
            return (value);
        };

        bool tryPop(T &value)
        {
            if (_queue.empty())
                return false;
            std::unique_lock<std::mutex> lock(_mutexQueue, std::defer_lock);
            value = _queue.front();
            _queue.pop();
            _cv.notify_all();
            return true;
        };

        const std::queue<T> &getQueue() const
        {
            return _queue;
        }

        const std::mutex &getMutex() const
        {
            return _mutexQueue;
        }

        const std::condition_variable &getCondition() const
        {
            return _cv;
        }

    private:
        std::queue<T> _queue;
        std::mutex _mutexQueue;
        std::condition_variable _cv;
};
