/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_close_door.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:54:45 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 23:16:35 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

# define DELTA_ANGLE 0.00001
# define DOOR_DISTANCE 100.0

static void	ft_close_door(t_player *player, char **map)
{
	int	i;
	int	x;
	int	y;

	i = (int) DOOR_DISTANCE;
	while (i > 0)
	{
		x = floor((player->x + i * cos(player->rotation_angle)) / TILE_SIZE);
		y = floor((player->y + i * sin(player->rotation_angle)) / TILE_SIZE);
		if (map[y][x] == 'O' && \
			!(x == floor(player->x / TILE_SIZE) && y == floor(player->y / TILE_SIZE)))
		{
			map[y][x] = 'C';
			return ;
		}
		i--;
	}
}

static void	ft_open_door(char **map, t_ray ray)
{
	int	x;
	int	y;

	x = floor(ray.wall_hit_x / TILE_SIZE);
	y = floor(ray.wall_hit_y / TILE_SIZE);
	if (!ray.was_hit_vertical && ray.is_ray_facing_up)
		y -= 1;
	else if (ray.was_hit_vertical && ray.is_ray_facing_left)
		x -= 1;
	map[y][x] = 'O';
}

void	ft_open_close_door(t_game_set *game_set)
{
	t_ray		*ray;
	int			i;

	ray = game_set->rays;
	i = 0;
	while (i < game_set->number_of_rays)
	{
		if (fabs(ray[i].angle -  game_set->player->rotation_angle) < DELTA_ANGLE)
		{
			if (ray[i].wall_hit_content == 'C' && ray[i].distance < DOOR_DISTANCE)
			{
				ft_open_door(game_set->scene->map, ray[i]);
				break ;
			}
			else
			{
				ft_close_door(game_set->player, game_set->scene->map);
				break ;
			}
		}
		i++;
	}
}
