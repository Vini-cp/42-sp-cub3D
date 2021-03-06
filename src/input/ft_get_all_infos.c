/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 03:05:24 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/22 02:45:43 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_initialize_game_set(t_game_set *game_set)
{
	game_set->scene = NULL;
	game_set->assets = NULL;
	game_set->player = NULL;
	game_set->window = NULL;
	game_set->rays = NULL;
}

static void	ft_get_number_of_lines(char *map_path, t_scene *scene)
{
	int		fd;
	int		read_output;
	char	*line;

	read_output = 1;
	scene->file_number_of_lines = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_print_error(E_FILE_DOES_NOT_EXISTS, scene, ft_free_scene);
	while (read_output == 1)
	{
		read_output = get_next_line(fd, &line);
		if (ft_strlen(line) > 0)
			scene->file_number_of_lines++;
		free(line);
	}
	close(fd);
}

static void	ft_get_file_infos(char *map_path, t_scene *scene)
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
		ft_print_error(E_FILE_DOES_NOT_EXISTS, scene, ft_free_scene);
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
}

void	ft_get_all_infos(char *map_path, t_game_set *game_set)
{
	ft_initialize_game_set(game_set);
	game_set->scene = malloc(sizeof(t_scene));
	ft_get_number_of_lines(map_path, game_set->scene);
	ft_get_file_infos(map_path, game_set->scene);
}
