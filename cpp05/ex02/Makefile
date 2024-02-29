NAME = 12travaux

CC = c++

CFLAG =  -std=c++98 -Wall -Werror -Wextra -g

SRCS =	main.cpp \
		PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		Bureaucrat.cpp \
		AForm.cpp

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

cleanf:
	@rm -f *_shrubbery.form
		@echo "removed shrubbery forms"

re: fclean all

.PHONY: all 
