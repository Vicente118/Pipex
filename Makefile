NAME = pipex

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = pipex.c utils.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@make bonus -C libft
	@printf "                                \r"
	@echo "██████╗  ██╗ ██████╗  ███████╗ ██╗  ██╗"
	@echo "██╔══██╗ ██║ ██╔══██╗ ██╔════╝ ╚██╗██╔╝"
	@echo "██████╔╝ ██║ ██████╔╝ █████╗    ╚███╔╝ "
	@echo "██╔═══╝  ██║ ██╔═══╝  ██╔══╝    ██╔██╗ "
	@echo "██║      ██║ ██║      ███████╗ ██╔╝ ██╗"
	@echo "╚═╝      ╚═╝ ╚═╝      ╚══════╝ ╚═╝  ╚═╝"
	@echo "                                   "
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

%.o : %.c
	@$(CC) -o $@ -c $< 

fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)
clean : 
	@make clean -C libft
	@$(RM) *.o

re : fclean all