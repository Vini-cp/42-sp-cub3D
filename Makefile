.PHONY:	clean fclean re all

NAME		:=	cub3d

LIBFT		:=	libft

CFLAGS		:=	-g3 -Wall -Wextra -Werror

LFLAGS		:=	-Llibft -lft -lm

MINILIBX	:= -lmlx -lXext -lX11

CC			:=	gcc

SRC			:=	main.c \
				draw/ft_build_images.c \
				draw/ft_draw_line.c \
				draw/ft_draw_player.c \
				draw/ft_draw_rays.c \
				draw/ft_draw_square.c \
				exit/ft_free_map.c \
				exit/ft_free_scene.c \
				exit/ft_free.c \
				exit/ft_print_error.c \
				hook/ft_exit_hook.c \
				hook/ft_key_press.c \
				hook/ft_key_release.c \
				hook/ft_mouse_exit.c \
				hook/ft_mouse_move.c \
				input/ft_assets_checker.c \
				input/ft_check_input.c \
				input/ft_get_all_infos.c \
				input/ft_get_floor_and_ceiling_colors.c \
				loop/ft_game_loop.c \
				loop/ft_load_window.c \
				loop/ft_move_player.c \
				loop/ft_render.c \
				loop/ft_update.c \
				map/ft_is_map_open.c \
				map/ft_map_checker.c \
				map/ft_load_player.c \
				map/ft_get_map.c \
				raycasting/ft_3d_viewer.c \
				raycasting/ft_cast_rays.c \
				raycasting/ft_horizontal_ray.c \
				raycasting/ft_vertical_ray.c \
				utils/ft_has_ray_collision.c \
				utils/ft_normalize_angle.c \
				utils/ft_point_distance.c

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
	valgrind --leak-check=full ./cub3d ./maps/minimalist.cub

fullvalgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d ./maps/minimalist.cub
