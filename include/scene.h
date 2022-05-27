/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:17:56 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 23:44:39 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define NUMBER_OF_ASSETS 6

# define PLAYER "./assets/player.xpm"
# define WALL "./assets/wall.xpm"
# define BACKGROUND "./assets/background.xpm"

# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF
# define DARK 0xFF000000
# define WHITE 0xFFFFFFFF
# define GRAY 0xFF808080
# define YELLOW 0xFF30FF30

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_assets
{
	t_image	enemy;
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	int		floor_color;
	int		ceiling_color;
}	t_assets;

typedef struct s_scene
{
	char	**map;
	char	**file_infos;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceiling_color;
	int		map_height;
	int		map_length;
	int		file_number_of_lines;
}	t_scene;

#endif
