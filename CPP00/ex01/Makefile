SRCS = PhoneBook.cpp GetterSetter.cpp add.cpp search.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
OBJS = $(SRCS:.c=.o)

NAME = phonebook

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean : $(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)
	
re : fclean $(NAME)

.PHONY : all clean fclean re