##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Vm makefile
##

## USEFUL DEF ########################

CXX			=	g++
RM			=	-rm -f
BIN			=	plazza
TEST_BIN	=	unit_tests

#######################################

## FILES ##############################

COMMUNICATION_FILES	=	MessageQueue.cpp\
						Serializing.cpp	\

RECEP_FILES	=	Reception.cpp			\

PIZZA_FILES	=	Pizza.cpp				\

ERROR_FILES	=	Error.cpp				\
				ParseError.cpp			\
				PizzaError.cpp			\
				CommunicationError.cpp	\
				ProcessesError.cpp 		\

KITCHEN_FILES =	Kitchen.cpp 			\
				Processes.cpp 			\

THREADPOOL_FILES =	ThreadPool.cpp 		\

TEST_FILES	=	MyUnitTests.cpp			\

#######################################


## SOURCES ############################

MAIN		=	Main.cpp

SRC			=	$(addprefix src/Reception/, $(RECEP_FILES))		\
				$(addprefix src/Pizza/, $(PIZZA_FILES))			\
				$(addprefix src/Error/, $(ERROR_FILES))			\
				$(addprefix src/Communication/, $(COMMUNICATION_FILES))	\
				$(addprefix src/kitchen/, $(KITCHEN_FILES))	\
				$(addprefix src/kitchen/Thread/, $(THREADPOOL_FILES))	\

TESTS		=	$(addprefix tests/, $(TEST_FILES))		\

#######################################

## OBJ ################################

MAIN_OBJ	=	$(MAIN:.cpp=.o)

SRC_OBJ		=	$(SRC:.cpp=.o)

TESTS_OBJ	=	$(TESTS:.cpp=.o)

#######################################

## FLAGS ##############################

CXXFLAGS	= -W -Wall -Wextra -Wl,--stack,10485760

DBGFLAGS	=	-k8 -g3 -ggdb

PTHREAD		=	-lpthread

INCLUDE		=	-iquote ./src/Reception/ -iquote ./src/Pizza/ -iquote ./src/Error/ -iquote ./src/Communication/ -iquote ./src/kitchen/ -iquote ./src/kitchen/Thread/

#######################################

## RULES ##############################

all : $(BIN)

$(BIN): $(MAIN_OBJ) $(SRC_OBJ)
	$(CXX) -o $(BIN) $(MAIN_OBJ) $(SRC_OBJ) $(PTHREAD)

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
	$(CXX) $(INCLUDE) -c -o $@ $<

re: fclean clean all

tests_run:  CXXFLAGS += --coverage
tests_run:  LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(TESTS_OBJ) $(SRC_OBJ)
	$(CXX) -o $(TEST_BIN) $(TESTS_OBJ) $(SRC_OBJ) $(LDFLAGS) $(INCLUDE)
	-./$(TEST_BIN)
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests
	@$(RM) $(TEST_BIN)

.PHONY: all $(BIN) clean fclean re tests_run

#######################################
