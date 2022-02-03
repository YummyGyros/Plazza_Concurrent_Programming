# Plazza_Concurrent_Programming

## The subject

The goal of the project was to make a simulation of a pizzeria. It is composed of a reception that accepts new orders and distribute them 
to kitchens, themselves distributing pizzas to cooks, themselves handling several pizzas.

Here's a few challenges of this project: load balancing, process and thread synchronization and communication.

## Build and run

Only g++ is required.

Otherwise simply:
```sh
make
./plazza -h
```

As an example (pizza type size quantity):
```sh
./plazza 1 3 5
regina XXL x2; fantasia M x3; margarita S x1
```
