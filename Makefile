RED=\033[0;34m 
GREEN=\033[0;32m
YELLOW=\033[0;34m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0;34m 

NAME = pipex

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = source/pipex.c source/utils.c source/process.c  source/utils2.c source/process_pipe.c\
	#    source/get_next_line.c source/get_next_line_utils.c
	   
OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@make bonus -C libft
	@printf "                                \r"
	@echo "                                   "
	@echo "\033[0;34m    ██████╗  ██╗ ██████╗  ███████╗ ██╗  ██╗"
	@echo "\033[0;34m    ██╔══██╗ ██║ ██╔══██╗ ██╔════╝ ╚██╗██╔╝"
	@echo "\033[0;34m    ██████╔╝ ██║ ██████╔╝ █████╗    ╚███╔╝ "
	@echo "\033[0;34m    ██╔═══╝  ██║ ██╔═══╝  ██╔══╝    ██╔██╗ "
	@echo "\033[0;34m    ██║      ██║ ██║      ███████╗ ██╔╝ ██╗"
	@echo "\033[0;34m    ╚═╝      ╚═╝ ╚═╝      ╚══════╝ ╚═╝  ╚═╝"
	@echo "                                   "
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

%.o : %.c
	@$(CC) -o $@ -c $< 

fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)

clean : 
	@make clean -C libft
	@$(RM) source/*.o

re : fclean all