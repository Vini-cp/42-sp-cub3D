/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 03:22:06 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 20:25:02 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

typedef struct s_helper
{
	t_enum_error	error_code;
	int				fd;
	int				is_map;
	int				number_of_assets;
	int				read_output;
	char			*line;
}	t_helper;

static t_helper	ft_initialize_helper(void)
{
	t_helper	helper;

	helper.error_code = E_SUCCESS;
	helper.read_output = 1;
	helper.is_map = 0;
	helper.number_of_assets = NUMBER_OF_ASSETS;
	return (helper);
}

static t_enum_error	ft_has_map_empty_lines(char *file_name, int map_height)
{
	t_helper	helper;

	helper = ft_initialize_helper();
	helper.fd = open(file_name, O_RDONLY);
	if (helper.fd < 0)
		return (E_FILE_DOES_NOT_EXISTS);
	while (helper.read_output == 1)
	{
		helper.read_output = get_next_line(helper.fd, &helper.line);
		if (ft_strlen(helper.line) > 0 && helper.number_of_assets)
			helper.number_of_assets--;
		else if (ft_strlen(helper.line) > 0 && \
					!(helper.number_of_assets) && !(helper.is_map))
		{
			helper.is_map = 1;
			map_height--;
		}
		else if (ft_strlen(helper.line) > 0 && helper.is_map)
			map_height--;
		else if (ft_strlen(helper.line) == 0 && helper.is_map && map_height)
			helper.error_code = E_MAP_HAS_EMPTY_LINES;
		free(helper.line);
	}
	close(helper.fd);
	return (helper.error_code);
}

static t_enum_error	ft_map_has_invalid_chars(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	while (i < scene->map_height)
	{
		j = 0;
		while (j < scene->map_length)
		{
			if (scene->map[i][j] != ' ' && scene->map[i][j] != '0' \
				&& scene->map[i][j] != '1' && scene->map[i][j] != 'N' \
				&& scene->map[i][j] != 'S' && scene->map[i][j] != 'E' \
				&& scene->map[i][j] != 'W')
				return (E_MAP_HAS_INVALID_CHARS);
			j++;
		}
		i++;
	}
	return (E_SUCCESS);
}

void	ft_map_checker(char *map_path, t_game_set *game_set)
{
	t_enum_error	error_code;

	ft_get_map(game_set->scene);
	error_code = ft_has_map_empty_lines(map_path, \
		(game_set->scene)->map_height);
	ft_print_error(error_code, game_set, ft_free);
	error_code = ft_map_has_invalid_chars(game_set->scene);
	ft_print_error(error_code, game_set, ft_free);
	ft_is_map_open(game_set->scene);
}
