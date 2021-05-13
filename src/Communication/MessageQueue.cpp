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
