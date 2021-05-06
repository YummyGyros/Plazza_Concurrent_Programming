/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-robin.levavasseur
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include "Mutex.hpp"

class ScopedLock {
    public:
        ScopedLock(Mutex);
        ~ScopedLock();
    protected:
    private:
        Mutex _temp;
};

#endif /* !SCOPEDLOCK_HPP_ */
