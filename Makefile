NAME = abstract_vm

FLAGS = -Wall -Wextra -Werror -std=c++11

INCLUDES = -I ./includes/ -I ./lexertk

SRC_FILE += main.cpp \
				classes/our_exceptions.cpp \
				commands.cpp \
				classes/OpFactory.cpp


.PHONY = all clean fclean re

all : $(NAME)

#pretty sure that this doesn't work the way that i want it to
ifneq ("$(wildcard $(lexertk/lexertk.hpp))","")
$(NAME) :
	@echo "already pulled submodules"
	@echo "\tBuilding $(NAME) executable\n"
	clang++ $(FLAGS) $(INCLUDES) $(SRC_FILE) -o $(NAME)

else
$(NAME) :
	git submodule init
	git submodule update
	@echo "pulled submodules"
	@echo "\tBuilding $(NAME) executable\n"
	clang++ $(FLAGS) $(INCLUDES) $(SRC_FILE) -o $(NAME)
endif

clean :

fclean : clean
	rm $(NAME)

re : fclean all

r :
	rm $(NAME);
	make all
