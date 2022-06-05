/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_floor_and_ceiling_colors.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:27:05 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/05 02:30:06 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_get_color(int *texture, char *color)
{
	char	**rgb;

	rgb = ft_split(color, ',');
	*texture = \
		((255 & 0xff) << 24) + \
		((ft_atoi(rgb[0]) & 0xff) << 16) + \
		((ft_atoi(rgb[1]) & 0xff) << 8) + \
		(ft_atoi(rgb[2]) & 0xff);
	free(rgb[2]);
	free(rgb[1]);
	free(rgb[0]);
	free(rgb);
}

static void	ft_free_rgb(char **rgb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

static t_enum_error	ft_check_color(char *color)
{
	char			**rgb;
	int				i;
	int				j;
	t_enum_error	error_code;

	i = 0;
	error_code = E_SUCCESS;
	rgb = ft_split(color, ',');
	while (rgb[i] != NULL)
	{
		j = 0;
		while (j < (int) ft_strlen(rgb[i]))
		{
			if (!ft_isdigit(rgb[i][j]))
				error_code = E_WRONG_COLOR_PARAMETER;
			j++;
		}
		i++;
	}
	if (i != 3)
		error_code = E_WRONG_COLOR_PARAMETER;
	ft_free_rgb(rgb, i);
	return (error_code);
}

void	ft_get_floor_and_ceiling_colors(t_game_set *game_set)
{
	t_enum_error	error_code;

	error_code = E_SUCCESS;
	game_set->assets = malloc(sizeof(t_assets));
	error_code = ft_check_color((game_set->scene)->floor_color);
	ft_print_error(error_code, game_set->scene, ft_free_scene);
	error_code = ft_check_color((game_set->scene)->ceiling_color);
	ft_print_error(error_code, game_set->scene, ft_free_scene);
	ft_get_color(&(game_set->assets)->floor_color, \
		(game_set->scene)->floor_color);
	ft_get_color(&(game_set->assets)->ceiling_color, \
		(game_set->scene)->ceiling_color);
}
