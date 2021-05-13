/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** MessageQueue
*/

#include "MessageQueue.hpp"

int MessageQueue::getMsgid()
{
    return _msgid;
}

MessageQueue::MessageQueue()
{
    key_t key = 0;
    int random_variable = 0;

    std::srand(std::time(nullptr));
    random_variable = std::rand()%100000;
    if (std::fopen(std::to_string(random_variable).c_str(), "w") == nullptr)
        throw CommunicationError(std::to_string(random_variable) + "Unable to create the Communication file.");
    key = ftok(std::to_string(random_variable).c_str(), 65);
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
