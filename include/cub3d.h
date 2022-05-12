/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:25:19 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 01:40:57 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define NUMBER_OF_ASSETS 6

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
}	t_enum_error;

typedef struct s_assets
{
	void	*player;
	void	*wall;
	void	*background;
	void	*exit;
	void	*collectible;
}	t_assets;

typedef struct s_player
{
	int	player_position_x;
	int	player_position_y;
	int	player_movements;
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

t_enum_error	ft_assets_checker(t_game_set *game_set);
t_enum_error	ft_check_input(int argc, char **argv);
t_enum_error	ft_get_all_infos(char *map_path, t_game_set *game_set);
t_enum_error	ft_get_map(t_scene *scene);
t_enum_error	ft_is_map_open(t_scene *scene);
t_enum_error	ft_map_checker(char *map_path, t_game_set *game_set);

void			ft_free_map(char **map, int size);
int				ft_free(t_game_set *game_set);
t_enum_error	ft_print_error(int error_code);

#endif
