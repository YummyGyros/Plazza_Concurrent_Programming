/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#pragma once

#include "ThreadPool.hpp"
#include "PizzaDefinitions.hpp"
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
    goatCheese,
    chiefLove
};

static const std::map<PizzaType, std::vector<ingredients_e>> Recipe = { 
    {Regina, {tomato, gruyere}},
    {Margarita, {tomato, gruyere, ham, mushrooms}},
    {Americana, {tomato, gruyere, steak}},
    {Fantasia, {tomato, eggplant, goatCheese, chiefLove}}
};


class Kitchen {
    public:
        Kitchen(float timeMul, std::size_t nbCooks, std::size_t restockTime);
        ~Kitchen();

        void startWork();
        void checkIsAlive();

    private:
        std::map<int, std::string> _ingredients;
        ThreadPool _threads;
        bool _isAlive;
        int _lifeTime;

        float _timeMul;
        std::size_t _nbCooks;
        std::size_t _restockTime;
};
