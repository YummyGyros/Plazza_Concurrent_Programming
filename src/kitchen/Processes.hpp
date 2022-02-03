/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** processes
*/

#pragma once

#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include "Kitchen.hpp"

class Processes
{
    public:
        Processes(Kitchen&);
        ~Processes();

    private:
        pid_t _pid;
        bool _status;
};
