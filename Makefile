RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME = pipex

NAME_BONUS = pipex_bonus

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = source/pipex.c source/utils.c source/process.c  source/utils2.c \
	   
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = src_bonus/pipex_bonus.c src_bonus/utils_bonus.c src_bonus/process_bonus.c  src_bonus/utils2_bonus.c \
		   # source/get_next_line.c source/get_next_line_utils.c

OBJS_BONUS =$(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

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
	@echo "                                    "
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS)
	@make bonus -C libft
	@printf "                                \r"
	@echo "                                   "
	@echo "\033[1;33m    ██████╗  ██╗ ██████╗  ███████╗ ██╗  ██╗"
	@echo "\033[1;33m    ██╔══██╗ ██║ ██╔══██╗ ██╔════╝ ╚██╗██╔╝"
	@echo "\033[1;33m    ██████╔╝ ██║ ██████╔╝ █████╗    ╚███╔╝ "
	@echo "\033[1;33m    ██╔═══╝  ██║ ██╔═══╝  ██╔══╝    ██╔██╗ "
	@echo "\033[1;33m    ██║      ██║ ██║      ███████╗ ██╔╝ ██╗"
	@echo "\033[1;33m    ╚═╝      ╚═╝ ╚═╝      ╚══════╝ ╚═╝  ╚═╝"
	@echo "                                    "
	@$(CC) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

%.o : %.c
	@$(CC) -o $@ -c $< 

fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME) $(NAME_BONUS)

clean : 
	@make clean -C libft
	@$(RM) source/*.o src_bonus/*.o

re : fclean all