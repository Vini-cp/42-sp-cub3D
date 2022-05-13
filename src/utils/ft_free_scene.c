/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:19:15 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 21:26:33 by vcordeir         ###   ########.fr       */
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
	free(scene);
}
