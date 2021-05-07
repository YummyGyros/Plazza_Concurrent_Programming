/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** step10
*/

#include "SafeQueue.hpp"
#include "ScopedLock.hpp"
#include "Thread.hpp"
#include <time.h>

struct args {
    SafeQueue<int> x;
};

void *producer(void *queue)
{
    args *test = dynamic_cast<args> (queue);
    srand(time(NULL));
    while (1) {
        test.x.push(rand() % 500);
    }
    pthread_exit(NULL);
}

void *consumer(void *queue)
{
    args *test = dynamic_cast<args> (queue);
    test.x.pop();
    pthread_exit(NULL);
}

int main(int ac, char **av)
{
    Thread stack[std::atoi(av[1])];
    Thread unstack[std::atoi(av[2])];
    args *ptr;
    int n = 0;

    while (n != std::atoi(av[1])) {
        stack[n].StartThread(producer, ptr);
        void *status;
        stack[n].JoinThread(status);
        n++;
    }
    n = 0;
    while (n != std::atoi(av[2])) {
        unstack[n].StartThread(consumer, ptr);
        void *status;
        unstack[n].JoinThread(status);
        n++;
    }
}