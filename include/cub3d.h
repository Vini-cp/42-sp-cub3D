/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:25:19 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 18:17:28 by vcordeir         ###   ########.fr       */
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
# include "player.h"
# include "scene.h"
# include "ray.h"

# define PI 3.1415926535f

# define ESC 65307
# define OPEN_DOOR 32
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define TILE_SIZE 64
# define SCALE 0.15

typedef enum e_enum_error
{
	E_SUCCESS,
	E_INVALID_INPUT,
	E_INVALID_FILE_EXTENSION,
	E_WRONG_COLOR_PARAMETER,
	E_MALLOC,
	E_MAP_HAS_EMPTY_LINES,
	E_FILE_DOES_NOT_EXISTS,
	E_MAP_HAS_INVALID_CHARS,
	E_MAP_IS_OPEN,
	E_MAP_HAS_NO_SPAWNING_POSITION,
	E_NULL_ASSET,
	E_COLOR_NOT_DIGIT,
	E_NO_PLAYER,
	E_MLX,
	E_MLX_WIN,
}	t_enum_error;

typedef struct s_window
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_game_set
{
	int			number_of_rays;
	int			window_width;
	int			window_height;
	int			**color_buffer;
	t_scene		*scene;
	t_assets	*assets;
	t_player	*player;
	t_window	*window;
	t_ray		*rays;
}	t_game_set;

void	ft_build_images(t_game_set *game_set);
void	ft_draw_line(t_window *window, t_player *player, float size, int color);
void	ft_draw_player(int x, int y, int color, t_window *window);
void	ft_draw_rays(t_game_set *game_set, int color);
void	ft_draw_square(int x_start, int y_start, int color, t_window *window);

void	ft_free_map(char **map, int size);
void	ft_free_scene(void *param);
void	ft_free(void *param);
void	ft_print_error(t_enum_error error_code, void *param,
			void (*free_param)(void *));

int		ft_exit_hook(t_game_set *game_set);
int		ft_key_press(int keycode, t_game_set *game_set);
int		ft_key_release(int keycode, t_game_set *game_set);
int		ft_mouse_exit(t_game_set *game_set);
int		ft_mouse_move(int x, int y, t_game_set *game_set);

void	ft_assets_checker(t_game_set *game_set);
void	ft_check_input(int argc, char **argv);
void	ft_get_all_infos(char *map_path, t_game_set *game_set);
void	ft_get_floor_and_ceiling_colors(t_game_set *game_set);

void	ft_game_loop(t_game_set *game_set);
void	ft_load_window(t_game_set *game_set);
void	ft_move_player(t_game_set *game_set);
void	ft_render(t_game_set *game_set);
int		ft_update(t_game_set *game_set);

void	ft_get_map(t_scene *scene);
void	ft_is_map_open(t_scene *scene);
void	ft_load_player(t_game_set *game_set);
void	ft_map_checker(char *map_path, t_game_set *game_set);

void	ft_3d_viewer(t_game_set *game_set);
void	ft_cast_rays(t_game_set *game_set);
void	ft_horizontal_ray(t_ray *ray, t_player *player, t_scene *scene);
void	ft_vertical_ray(t_ray *ray, t_player *player, t_scene *scene);

int		ft_has_ray_collision(t_scene *scene, t_ray_helper *ray);
float	ft_normalize_angle(float angle);
void	ft_open_close_door(t_game_set *game_set);
int		ft_player_collision(t_scene *scene, float x, float y);
float	ft_point_distance(float x1, float y1, float x2, float y2);

#endif
