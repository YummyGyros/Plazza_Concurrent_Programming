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

typedef struct data_s {
    long mtype;
    int type;
    int size;
} data_t;

class MessageQueue {
    public:
        MessageQueue(const std::string &name);
        ~MessageQueue();

        void sendMsg(data_t pizza, int msgid);
        void recvMsg();
    protected:
    private:
        int _msgid;
};

#endif /* !MESSAGEQUEUE_HPP_ */
