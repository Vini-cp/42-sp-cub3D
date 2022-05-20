/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:25:19 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 04:02:37 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

# define PI 3.142857

# define NUMBER_OF_ASSETS 6
# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

#define TILE_SIZE 20
#define LENGTH 800
#define HEIGHT 600

# define WALK_SPEED 1.0f
# define ROT_SPEED 0.1f

# define RED 0x00FF0000
# define BLUE 0x000000FF
# define DARK 0x00000000

typedef enum e_enum_error
{
	E_SUCCESS,
	E_INVALID_INPUT,
	E_INVALID_FILE_EXTENSION,
	E_MALLOC,
	E_MAP_HAS_EMPTY_LINES,
	E_FILE_DOES_NOT_EXISTS,
	E_MAP_HAS_INVALID_CHARS,
	E_MAP_IS_OPEN,
	E_MAP_HAS_NO_SPAWNING_POSITION,
	E_NULL_ASSET,
	E_NO_PLAYER,
	E_MLX,
	E_MLX_WIN,
}	t_enum_error;

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}	t_image;

typedef struct s_assets
{
	t_image	player;
	t_image	wall;
	t_image	background;
	t_image	enemy;
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	t_image	floor;
	t_image	ceilling;
}	t_assets;

typedef struct s_player
{
	float	x;
	float	y;
	char	initial_direction;
	int		turn_direction;
    int		walk_direction;
    float	rotation_angle;
}	t_player;

typedef struct s_window
{
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_scene
{
	char	**map;
	char	**file_infos;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceilling_color;
	int		map_height;
	int		map_length;
	int		file_number_of_lines;
}	t_scene;

typedef struct s_game_set
{
	int			game_won;
	t_scene		*scene;
	t_assets	*assets;
	t_player	*player;
	t_window	*window;
}	t_game_set;

void	ft_draw_line(t_window *window, t_player *player, float size, int color);
void	ft_draw_player(int x, int y, int color, t_window *window);
void	ft_draw_square(int x_start, int y_start, int color, t_window *window);

void	ft_assets_checker(t_game_set *game_set);
void	ft_check_input(int argc, char **argv);
void	ft_get_all_infos(char *map_path, t_game_set *game_set);

void	ft_build_images(t_game_set *game_set);
void	ft_game_loop(t_game_set *game_set);
void	ft_load_window(t_game_set *game_set);
void	ft_move_player(t_game_set *game_set);
void	ft_render(t_game_set *game_set);
int		ft_update(t_game_set *game_set);

void	ft_get_map(t_scene *scene);
void	ft_is_map_open(t_scene *scene);
void	ft_load_player(t_game_set *game_set);
void	ft_map_checker(char *map_path, t_game_set *game_set);

void	ft_free_map(char **map, int size);
void	ft_free_scene(void *param);
void	ft_free(void *param);
void	ft_print_error(t_enum_error error_code, void *param,
			void (*free_param)(void *));

#endif
