NAME		= claptrap

CXX			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CFLAGS) -o $@ $(OBJ)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
