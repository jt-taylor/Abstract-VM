NAME = abstract_vm

FLAGS = -Wall -Wextra -Werror -std=c++11

INCLUDES = -I ./includes/ -I ./lexertk

SRC_FILE += main.cpp \
				./classes/our_exceptions.cpp
.PHONY = all clean fclean re

all : $(NAME)

$(NAME) :
	@echo "\tBuilding $(NAME) executable\n"
	clang++ $(FLAGS) $(INCLUDES) $(SRC_FILE) -o $(NAME)

clean :

fclean : clean
	rm $(NAME)

re : fclean all

r :
	rm $(NAME);
	make all
