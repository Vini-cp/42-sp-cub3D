/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 03:47:15 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 22:44:51 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_get_map_length(t_scene *scene)
{
	int	i;
	int	length;
	int	max_length;

	i = 0;
	max_length = 0;
	while (i < scene->map_height)
	{
		length = ft_strlen(scene->file_infos[i + NUMBER_OF_ASSETS]);
		if (length > max_length)
			max_length = length;
		i++;
	}
	return (max_length);
}

static char	*ft_fill_line_with_espaces(char *line, int size)
{
	int		i;
	int		length;
	char	*strconcat;

	length = ft_strlen(line);
	strconcat = (char *)malloc((size + 1) * sizeof(char));
	if (!strconcat)
		return (NULL);
	i = 0;
	while (i < length)
	{
		strconcat[i] = line[i];
		i++;
	}
	while (i < size)
	{
		strconcat[i] = ' ';
		i++;
	}
	strconcat[i] = '\0';
	return (strconcat);
}

static void	ft_create_map(t_scene *scene)
{
	int	i;
	int	length;

	i = 0;
	scene->map = malloc(scene->map_height * sizeof(char *));
	while (i < scene->map_height)
	{
		length = ft_strlen(scene->file_infos[i + NUMBER_OF_ASSETS]);
		if (length < scene->map_length)
			scene->map[i] = \
				ft_fill_line_with_espaces(\
					scene->file_infos[i + NUMBER_OF_ASSETS], \
					scene->map_length);
		else
			scene->map[i] = ft_strdup(scene->file_infos[i + NUMBER_OF_ASSETS]);
		if (scene->map == NULL)
			ft_print_error(E_MALLOC, scene, ft_free_scene);
		i++;
	}
}

void	ft_get_map(t_scene *scene)
{
	scene->map_height = scene->file_number_of_lines - NUMBER_OF_ASSETS;
	scene->map_length = ft_get_map_length(scene);
	ft_create_map(scene);
}
