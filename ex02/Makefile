NAME		= phonebook

CXX			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= PhoneBook.cpp Contact.cpp

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
