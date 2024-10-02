NAME		= iter

CXX			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++17

SRC			= main.cpp

OBJ			= $(SRC:.cpp=.o)
DEPS		= $(SRC:.cpp=.d)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
			rm -f $(OBJ) $(DEPS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
