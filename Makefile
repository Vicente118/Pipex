NAME = pipex

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = source/pipex.c source/utils.c source/process.c  source/utils2.c \
	#    source/get_next_line.c source/get_next_line_utils.c
	   
OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@make bonus -C libft
	@printf "                                \r"
	@echo "                                   "
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
	@$(RM) source/$(NAME)

clean : 
	@make clean -C libft
	@$(RM) source/*.o

re : fclean all