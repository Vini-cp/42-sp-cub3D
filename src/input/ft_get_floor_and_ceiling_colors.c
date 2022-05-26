/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_floor_and_ceiling_colors.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:27:05 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/26 01:27:30 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_get_color(int *texture, char *color)
{
	char	**rgb;

	rgb = ft_split(color, ',');
	*texture = (ft_atoi(rgb[2]) & 0xFF);
	*texture += (ft_atoi(rgb[1]) & 0xFF) << 8;
	*texture += (ft_atoi(rgb[0]) & 0xFF) << 16;
	*texture += (255 & 0xFF) << 24;
	free(rgb[2]);
	free(rgb[1]);
	free(rgb[0]);
	free(rgb);
}

void	ft_get_floor_and_ceiling_colors(t_game_set *game_set)
{
	game_set->assets = malloc(sizeof(t_assets));
	ft_get_color(&(game_set->assets)->floor_color, \
		(game_set->scene)->floor_color);
	ft_get_color(&(game_set->assets)->ceiling_color, \
		(game_set->scene)->ceiling_color);
}
