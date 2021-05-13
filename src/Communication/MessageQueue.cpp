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
    _communicationFile = std::to_string(random_variable);
    if (std::fopen(_communicationFile.c_str(), "w") == nullptr)
        throw CommunicationError(_communicationFile + "Unable to create the Communication file.");
    key = ftok(_communicationFile.c_str(), 65);
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
    std::remove(_communicationFile.c_str());
}
