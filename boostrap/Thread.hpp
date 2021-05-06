/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** Thread
*/

#pragma once
#include "pthread.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

class Thread {
    public:
        Thread();
        ~Thread();

        bool Status();
        void StartThread(void *(*)(void *), void *);
        void JoinThread(void *status);
        void Wait(int);
        void Death();

    protected:
    private:
        bool _isAlive;
        pthread_t _threads;
};