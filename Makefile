NAME = pipex
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = main.c\

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
LIBFT_DIR = libft
INCLUDES = -I$(LIBFT_DIR) -Iincludes 

$(NAME): $(OBJS) $(LIBFT)
	@cc $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

.c.o:
	@cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME) $(LIBFT_DIR)/$(LIBFT)

re: fclean all

tests :
	@touch file1 file2
	@echo Hello World > file1

end :
	$(RM) file1 file2

.PHONY: all clean fclean re bonus rebonus