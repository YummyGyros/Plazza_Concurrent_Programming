/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** MessageQueue
*/

#include "MessageQueue.hpp"

int MessageQueue::getMsgid() const
{
    return _msgid;
}

MessageQueue::MessageQueue(const std::string &name)
{
    key_t key = 0;

    _communicationFile = name;
    if (std::fopen(_communicationFile.c_str(), "w") == nullptr)
        throw CommunicationError(_communicationFile + "Unable to create the Communication file.");
    key = ftok(_communicationFile.c_str(), 65);
    if (key == -1)
        throw CommunicationError("ftok failed.");
    _msgid = msgget(key, 0666 | IPC_CREAT);
    if (_msgid == -1)
        throw CommunicationError("msgget failed.");
}

MessageQueue::MessageQueue(const MessageQueue &queue)
{
    _msgid = queue.getMsgid();
    _communicationFile = queue.getFile();
}

MessageQueue::~MessageQueue()
{
    msgctl(_msgid, IPC_RMID, NULL);
    std::remove(_communicationFile.c_str());
}

const std::string &MessageQueue::getFile() const
{
    return _communicationFile;
}