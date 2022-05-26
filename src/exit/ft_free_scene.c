/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:19:15 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/26 01:30:53 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_scene(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (scene->file_infos)
		ft_free_map(scene->file_infos, scene->file_number_of_lines);
	if (scene->map)
		ft_free_map(scene->map, scene->map_height);
	if (scene->north_texture)
		free(scene->north_texture);
	if (scene->south_texture)
		free(scene->south_texture);
	if (scene->west_texture)
		free(scene->west_texture);
	if (scene->east_texture)
		free(scene->east_texture);
	if (scene->floor_color)
		free(scene->floor_color);
	if (scene->ceiling_color)
		free(scene->ceiling_color);
	free(scene);
}
