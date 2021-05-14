/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** kitchen
*/

#pragma once

#include <map>
#include <chrono>
#include <vector>

#include "SafeQueue.hpp"
#include "ThreadPool.hpp"
#include "PizzaDefinitions.hpp"
#include "MessageQueue.hpp"

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
        Kitchen(const std::string &name, float timeMul, std::size_t nbCooks, std::size_t restockTime);
        ~Kitchen();

        void startWork();
        void checkIsAlive();
        const MessageQueue &getMessageQueue() const;

    private:
        MessageQueue _msg;
        float _timeMul;
        std::size_t _nbCooks;
        std::size_t _restockTime;

        std::size_t _totalPizze;
        bool _isAlive;
        int _lifeTime;

        ThreadPool _threads;
        std::map<ingredients_e, std::size_t> _fridge;

        SafeQueue<std::pair<PizzaType, PizzaSize>> _queue;
};
