NAME = zombie

CC = c++

CFLAG =  -std=c++98 -Wall -Werror -Wextra -g

SRCS =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)
		

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean:
		@rm -f $(OBJS)
			@echo clean $(OBJS)

fclean: clean
		@rm -f $(NAME)
			@echo clean $(NAME)

re: fclean all

.PHONY: all 
