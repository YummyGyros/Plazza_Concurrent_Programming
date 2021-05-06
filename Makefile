##
## EPITECH PROJECT, 2021
## nanotekspice
## File description:
## Makefile
##

SRC	=\


MAIN	=\

TESTS	=	

CXXFLAGS	=	-Wall -Wextra -lpthread\

CPPFLAGS	=	-iquote./ -iquote..

OBJ	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

CRITERION	=	-l criterion --coverage

NAME	=	plazza

UNIT	=	unit_tests

CC	=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CXXFLAGS) -o $(NAME) --std=c++17

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

clean_test:
	$(RM) *.gcda *.gcno

fclean_test: clean_test
	$(RM) $(UNIT)

debug: CPPFLAGS += -g3 -ggdb
debug: $(NAME)

re:	fclean	all

tests_run: fclean_test
	$(CC) $(SRC) $(TESTS) $(CXXFLAGS) $(CRITERION) -o $(UNIT) $(CPPFLAGS)
	./$(UNIT)
