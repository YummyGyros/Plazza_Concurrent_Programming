/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <cstddef>

class Reception {
    public:
        Reception();
        ~Reception();

    protected:
    private:
        float timeMultiplier;
        std::size_t cooks1Kitchen;
        std::size_t restockTime;
};

#endif /* !RECEPTION_HPP_ */
