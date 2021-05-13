/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#pragma once

#include "Thread/ThreadPool.hpp"
#include <map>
#include <chrono>
#include <vector>

enum ingredients_e
{
    tomato,
    gruyere,
    ham,
    mushrooms,
    steak,
    eggplant,
    goat_cheese,
    chief_love
};

enum  PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

static const std::map<PizzaType, std::vector<ingredients_e>> Recipe = { 
    {Regina, {tomato, gruyere}},
    {Margarita, {tomato, gruyere, ham, mushrooms}},
    {Americana, {tomato, gruyere, steak}},
    {Fantasia, {tomato, eggplant, goat_cheese, chief_love}}
};


class Kitchen {
    public:
        Kitchen(int);
        ~Kitchen();

        void startWork();
        void checkIsAlive();

    private:
        std::map<ingredients_e, int> _fridge;
        ThreadPool _threads;
        bool _isAlive;
        int _lifeTime;
        int _maxCooks;
};
