/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** SafeQueue
*/

#include "SafeQueue.hpp"

template <class T>
SafeQueue<T>::SafeQueue()
{
}

template <class T>
SafeQueue<T>::~SafeQueue()
{
}

template <class T>
void SafeQueue<T>::push(T value)
{
    _queue.push(value);
}

template <class T>
bool SafeQueue<T>::tryPop(T &value)
{
    if (_queue.empty())
        return false;
    value = _queue.front();
    _queue.pop();
    return true;
}

template <class T>
T SafeQueue<T>::pop()
{
    int value;

    while (1) {
        if (tryPop(value))
            return value;
        else {
            std::chrono::milliseconds dura(200);
            std::this_thread::sleep_for(dura);
        }
    }
}