/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** MessageQueue
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "MessageQueue.hpp"
#include "CommunicationError.hpp"

void MessageQueue::recvMsg()
{
    data_t pizza;

    std::cout << "jattends" << std::endl;
    if (msgrcv(_msgid, &pizza, sizeof(data_t), 1, 0) == -1)
        throw CommunicationError("msgrcv failed.");
    std::cout << "??" << std::endl;
    std::cout << pizza.type << ": " << pizza.size << std::endl;
}

void MessageQueue::sendMsg(data_t pizza, int msgid)
{
    if (msgsnd(msgid, &pizza, sizeof(data_t), 0) == -1)
        throw CommunicationError("msgsnd failed.");
}

MessageQueue::MessageQueue(const std::string &name)
{
    key_t key = ftok(name.c_str(), 65);

    if (key == -1)
        throw CommunicationError("ftok failed.");
    _msgid = msgget(key, 0666 | IPC_CREAT);
    if (_msgid == -1)
        throw CommunicationError("msgget failed.");
    std::cout << _msgid << std::endl;
}

MessageQueue::~MessageQueue()
{
    msgctl(_msgid, IPC_RMID, NULL);
}
