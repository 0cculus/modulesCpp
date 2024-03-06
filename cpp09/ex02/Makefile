NAME = fordjohnson

CC = c++

CFLAG =  -std=c++98 -Wall -Werror -Wextra -g

SRCS =	main.cpp \
		PmergeMe.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)
		

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAG) -c $(SRCS)

clean:
		@rm -f $(OBJS)
			@echo clean $(OBJS)

fclean: clean
		@rm -f $(NAME)
			@echo clean $(NAME)

re: fclean all

.PHONY: all 
