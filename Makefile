.PHONY:	clean fclean re all

NAME		:=	cub3d

LIBFT		:=	libft

CFLAGS		:=	-g3 -Wall -Wextra -Werror

LFLAGS		:=	-Llibft -lft

MINILIBX	:= -lmlx -lXext -lX11

CC			:=	gcc

SRC			:=	main.c \
				map/ft_check_input.c \
				utils/ft_print_error.c

SRC_FOLDER 	:= src

OBJ_FOLDER	:= obj

SRCS 		:= $(addprefix ${SRC_FOLDER}/, ${SRC})

OBJS 		:= $(addprefix ${OBJ_FOLDER}/, ${SRCS:.c=.o})

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME)	: $(OBJS)
	make  -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(MINILIBX) -o $(NAME)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C ${LIBFT} clean
	rm -rf $(OBJ_FOLDER)

fclean: clean
	make -C ${LIBFT} fclean
	rm -rf $(NAME)

re: fclean ${NAME}

do	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

valgrind:
	valgrind --leak-check=full ./cub3d ./maps/

fullvalgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./minishell
