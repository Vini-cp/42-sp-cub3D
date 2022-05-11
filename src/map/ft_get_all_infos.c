/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 03:05:24 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/11 23:41:17 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_enum_error	ft_get_number_of_lines(char *map_path, t_scene *scene)
{
	int		fd;
	int		read_output;
	char	*line;

	read_output = 1;
	scene->file_number_of_lines = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (E_FILE_DOES_NOT_EXISTS);
	while (read_output == 1)
	{
		read_output = get_next_line(fd, &line);
		if (ft_strlen(line) > 0)
			scene->file_number_of_lines++;
		free(line);
	}
	close(fd);
	return (E_SUCCESS);
}

static t_enum_error	ft_get_file_infos(char *map_path, t_scene *scene)
{
	int		i;
	int		fd;
	int		read_output;
	char	*line;

	i = 0;
	read_output = 1;
	scene->file_infos = malloc(scene->file_number_of_lines * sizeof(char *));
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (E_FILE_DOES_NOT_EXISTS);
	while (read_output == 1)
	{
		read_output = get_next_line(fd, &line);
		if (ft_strlen(line) > 0)
		{
			scene->file_infos[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	close(fd);
	return (E_SUCCESS);
}

t_enum_error	ft_get_all_infos(char *map_path, t_game_set *game_set)
{
	t_enum_error	error_code;

	game_set->scene = malloc(sizeof(t_scene));
	error_code = ft_get_number_of_lines(map_path, game_set->scene);
	if (error_code != E_SUCCESS)
		return (ft_print_error(error_code));
	error_code = ft_get_file_infos(map_path, game_set->scene);
	if (error_code != E_SUCCESS)
		return (ft_print_error(error_code));
	return (E_SUCCESS);
}
