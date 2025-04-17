NAME = pipex
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = main.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		cc $(FLAGS) $(OBJS) -o $(NAME)

.c.o:
		@cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus rebonus