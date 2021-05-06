/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** step6
*/

#include "SafeQueue.hpp"
#include "ScopedLock.hpp"
#include "Thread.hpp"
#include <time.h>

void *producer(void *queue)
{
    srand(time(NULL));
    while (1) {
        reinterpret_cast<SafeQueue &> (queue).push(rand() % 500);
    }
    pthread_exit(NULL);
}

void *consumer(void *queue)
{
    while (1) {
        int value;
        if (reinterpret_cast<SafeQueue &> (queue).tryPop(value))
            std::cout << value << std::endl;
        else {
            std::chrono::milliseconds dura(2000);
            std::this_thread::sleep_for(dura);
            std::cout << "wait\n";
        }
    }
    pthread_exit(NULL);
}

int main()
{
    Thread pro;
    Thread con;
    SafeQueue<int> queue;

    pro.StartThread(producer, (void *)&queue);
    con.StartThread(consumer, (void *)&queue);
    void *status1;
    void *status2;
    pro.JoinThread(status1);
    con.JoinThread(status2);
}