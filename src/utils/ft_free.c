/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:13:06 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/12 22:57:33 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_free(t_game_set *game_set)
{
	t_scene	*scene;

	if (game_set->scene)
	{
		scene = (game_set->scene);
		if (scene->file_infos)
			ft_free_map(scene->file_infos, scene->file_number_of_lines);
		if (scene->map)
			ft_free_map(scene->map, scene->map_height);
		free(scene);
	}
	return (0);
}
