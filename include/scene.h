/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:17:56 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 20:57:43 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define NUMBER_OF_ASSETS 6

# define RED 0x00FF0000
# define BLUE 0x000000FF
# define DARK 0x00000000

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

#endif
