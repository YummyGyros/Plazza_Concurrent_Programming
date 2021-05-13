/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** MessageQueue
*/

#ifndef MESSAGEQUEUE_HPP_
#define MESSAGEQUEUE_HPP_

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include "Pizza.hpp"
#include <sys/msg.h>
#include "CommunicationError.hpp"

typedef struct pizza_order_s {
    long mtype;
    PizzaType type;
    PizzaSize size;
} pizza_order_t;

typedef struct status_s {
    long mytype;
    std::size_t tomato;
    std::size_t gruyere;
    std::size_t ham;
    std::size_t mushrooms;
    std::size_t steak;
    std::size_t eggplant;
    std::size_t goatCheese;
    std::size_t chiefLove;
    std::size_t pizza;
} status_t;

class MessageQueue {
    public:
        MessageQueue(const std::string &name);
        ~MessageQueue();

        template<typename T>
        void sendMsg(T msg, int msgid);
        template<typename T>
        T recvMsg();
    protected:
    private:
        int _msgid;
};

#endif /* !MESSAGEQUEUE_HPP_ */
