/*
** EPITECH PROJECT, 2021
** CCP_Concurrent_Programming
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include " IPizza.hpp"
#include "PizzaDefinitions.hpp"
#include <string>
#include <map>

class Pizza : public IPizza {
    public:
        ~Pizza() override;
        Pizza(PizzaType _type, PizzaSize _size) noexcept;
        Pizza(const std::string &type, const std::string &size);
        bool operator==(const Pizza &rhs) const;

        PizzaType getType() const override;
        PizzaSize getSize() const override;
        const std::string &getTypeStr() const override;
        const std::string &getSizeStr() const override;
        const std::vector<Ingredients> &getRecipe() const override;

        bool getIsCooked() const override;
        void setIsCooked(const bool isCooked) override;
    protected:
    private:
        std::string _typeStr;
        PizzaType _type;

        std::string _sizeStr;
        PizzaSize _size;

        std::vector<Ingredients> _recipe;
        bool _isCooked;
};

#endif /* !PIZZA_HPP_ */
