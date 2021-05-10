##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Vm makefile
##

## USEFUL DEF ########################

CC			=	g++
RM			=	-rm -f
BIN			=	plazza
TEST_BIN	=	unit_tests

#######################################

## FILES ##############################

SRC_FILES	=	Reception.cpp			\

TEST_FILES	=	MyUnitTests.cpp			\

#######################################


## SOURCES ############################

MAIN		=	Main.cpp

SRC			=	$(addprefix src/, $(SRC_FILES))		\

TESTS		=	$(addprefix tests/, $(TEST_FILES))		\

#######################################

## OBJ ################################

MAIN_OBJ	=	$(MAIN:.cpp=.o)

SRC_OBJ		=	$(SRC:.cpp=.o)

TESTS_OBJ	=	$(TESTS:.cpp=.o)

#######################################

## FLAGS ##############################

CPPFLAGS	=	-W -Wall -Wextra -Werror

DBGFLAGS	=	-k8 -g3 -ggdb

LDFLAGS		=

INCLUDE		=	-iquote ./src/

#######################################

## RULES ##############################

all : $(BIN)

$(BIN): $(MAIN_OBJ) $(SRC_OBJ)
	$(CC) -o $(BIN) $(MAIN_OBJ) $(SRC_OBJ) $(CFLAGS) $(LDFLAGS)

## Clear
clean:
	@$(RM) $(MAIN_OBJ)
	@$(RM) $(SRC_OBJ)
	@$(RM) $(TESTS_OBJ)
	@$(RM) Makefile~
	@$(RM) src/**/*.gc*
	@$(RM) src/*.gc*
	@$(RM) tests/*.gc*

fclean: clean
	@$(RM) $(BIN)
	@$(RM) $(TEST_BIN)

## GCOVR NEEDS:
%.o:    %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

re: fclean clean all

tests_run:  CFLAGS += --coverage
tests_run:  LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(TESTS_OBJ) $(SRC_OBJ)
	$(CC) -o $(TEST_BIN) $(TESTS_OBJ) $(SRC_OBJ) $(CFLAGS) $(LDFLAGS) $(INCLUDE)
	-./$(TEST_BIN)
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests
	@$(RM) $(TEST_BIN)

.PHONY: all $(BIN) clean fclean re tests_run

#######################################
