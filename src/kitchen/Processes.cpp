/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** processes
*/

#include "Processes.hpp"
#include "ProcessesError.hpp"

Processes::Processes(Kitchen &kitchen)
{
    _status = false;
    _pid = fork();
    if (_pid == 0) {
        kitchen.startWork();
        std::exit(0);
    }
    else if (_pid < 0) {
        throw ProcessesError("Fork failed.");
        std::exit(-1);
    }
    else
        _status = true;
}

Processes::~Processes()
{
    _status = false;
}