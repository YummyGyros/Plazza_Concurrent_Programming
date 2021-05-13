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

typedef struct pizza_order_s {
    long mtype;
    int type;
    int size;
} pizza_order_t;

typedef struct status_s {
    long mytype;
    int tomato;
    int gruyere;
    int ham;
    int mushrooms;
    int steak;
    int eggplant;
    int goat_cheese;
    int chief_love;
    int cooks;
} status_t;

class MessageQueue {
    public:
        MessageQueue(const std::string &name);
        ~MessageQueue();

        template<typename T>
        void sendMsg(T msg, int msgid) {
            if (msgsnd(msgid, &pizza, sizeof(T), 0) == -1)
                throw CommunicationError("msgsnd failed.");
        };
        template<typename T>
        T recvMsg() {
            T pizza;

            if (msgrcv(_msgid, &pizza, sizeof(T), 1, 0) == -1)
                throw CommunicationError("msgrcv failed.");
            std::cout << pizza.type << ": " << pizza.size << std::endl;
            return pizza;
        };
    protected:
    private:
        int _msgid;
};

#endif /* !MESSAGEQUEUE_HPP_ */
