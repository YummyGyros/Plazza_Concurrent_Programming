/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** step1
*/

#include "ScopedLock.hpp"
#include "Thread.hpp"

void *inc(void *n)
{
    ScopedLock test(Mutex tmp());
    std::cout << (long)n << std::endl;
    pthread_exit(NULL);
}

int main()
{
    Thread threads[3];
    long int i = 0;

    while (i < 3) {
        threads[i].StartThread(inc, (void *)i);
        i++;
    }
    i = 0;
    while (i < 3) {
        void* status;
        threads[i].JoinThread(status);
        i++;
    }
}