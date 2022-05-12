/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:46:40 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/11 21:24:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_initialize_textures(t_scene *scene)
{
	scene->north_texture = NULL;
	scene->south_texture = NULL;
	scene->west_texture = NULL;
	scene->east_texture = NULL;
	scene->floor_color = NULL;
	scene->ceilling_color = NULL;
}

static void	ft_get_assets(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < NUMBER_OF_ASSETS)
	{
		if (ft_strnstr(scene->file_infos[i], "NO", 2) != NULL)
			scene->north_texture = \
				ft_strdup(ft_strrchr(scene->file_infos[i], ' ') + 1);
		else if (ft_strnstr(scene->file_infos[i], "SO", 2) != NULL)
			scene->south_texture = \
				ft_strdup(ft_strrchr(scene->file_infos[i], ' ') + 1);
		else if (ft_strnstr(scene->file_infos[i], "WE", 2) != NULL)
			scene->west_texture = \
				ft_strdup(ft_strrchr(scene->file_infos[i], ' ') + 1);
		else if (ft_strnstr(scene->file_infos[i], "EA", 2) != NULL)
			scene->east_texture = \
				ft_strdup(ft_strrchr(scene->file_infos[i], ' ') + 1);
		else if (ft_strnstr(scene->file_infos[i], "F ", 2) != NULL)
			scene->floor_color = \
				ft_strdup(ft_strrchr(scene->file_infos[i], ' ') + 1);
		else if (ft_strnstr(scene->file_infos[i], "C ", 2) != NULL)
			scene->ceilling_color = \
				ft_strdup(ft_strrchr(scene->file_infos[i], ' ') + 1);
		i++;
	}
}

static t_enum_error	ft_is_asset_null(t_scene *scene)
{
	if (scene->north_texture == NULL || scene->south_texture == NULL || \
		scene->west_texture == NULL || scene->east_texture == NULL || \
		scene->floor_color == NULL || scene->ceilling_color == NULL)
		return (E_NULL_ASSET);
	return (E_SUCCESS);
}

t_enum_error	ft_assets_checker(t_game_set *game_set)
{
	t_enum_error	error_code;

	ft_initialize_textures(game_set->scene);
	ft_get_assets(game_set->scene);
	error_code = ft_is_asset_null(game_set->scene);
	return (error_code);
}
