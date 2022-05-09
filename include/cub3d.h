/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:25:19 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/09 03:56:43 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef enum e_enum_error
{
	E_SUCCESS,
	E_INVALID_INPUT,
	E_INVALID_FILE_EXTENSION,
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
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceilling_color;
	int		map_height;
	int		no_collectibles;
	int		no_exits;
}	t_scene;

typedef struct s_game_set
{
	int			game_won;
	t_scene		*scene;
	t_assets	*assets;
	t_player	*player;
	t_window	*window;
}	t_game_set;

t_enum_error	ft_check_input(int argc, char **argv);
t_enum_error	ft_print_error(int error_code);

#endif
