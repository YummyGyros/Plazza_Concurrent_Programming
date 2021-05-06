/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** Thread
*/

#include "Thread.hpp"

Thread::Thread()
{
}

Thread::~Thread()
{
    _isAlive = false;
}

bool Thread::Status()
{
    return _isAlive;
}

void Thread::StartThread(void *(*func)(void *), void *arg)
{
    if (pthread_create(&_threads, NULL, func, arg) != 0)
            std::cout << "Error in thread creation: " << std::endl;
    _isAlive = true;
}

void Thread::JoinThread(void *status)
{
    if (pthread_join(_threads, &status) != 0)
        std::cout << "Error in thread join: " << std::endl;
}

void Thread::Death()
{
    _isAlive = false;
    pthread_exit(NULL);
}

void Thread::Wait(int time)
{
    std::chrono::milliseconds dura(time);
    std::this_thread::sleep_for(dura);
}