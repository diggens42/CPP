NAME		= animal

CXX			= c++
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp 

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
