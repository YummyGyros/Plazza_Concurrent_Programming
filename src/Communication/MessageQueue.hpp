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
#include <sys/msg.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "Pizza.hpp"
#include "CommunicationError.hpp"

typedef struct pizza_order_s {
    long mtype;
    int id;
    PizzaType type;
    PizzaSize size;
    bool destroy;
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
        MessageQueue(const MessageQueue &queue);
        ~MessageQueue();

        template<typename T>
        void sendMsg(T msg, int msgid)
        {
            if (msgsnd(msgid, &msg, sizeof(T), 0) == -1)
                throw CommunicationError("msgsnd failed.");
        }
        template<typename T>
        T recvMsg()
        {
            T pizza;

            if (msgrcv(_msgid, &pizza, sizeof(T), 1, IPC_NOWAIT) == -1)
                throw CommunicationError("msgrcv: No message received.");
            return pizza;
        }

        int getMsgid() const;
        const std::string &getFile() const;
    protected:
    private:
        int _msgid;
        std::string _communicationFile;
};

#endif /* !MESSAGEQUEUE_HPP_ */
