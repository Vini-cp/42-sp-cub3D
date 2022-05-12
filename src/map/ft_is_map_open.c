/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:55:23 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/12 22:52:36 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_enum_error	ft_check_first_last_line(char *line, int line_length)
{
	int	i;

	i = 0;
	while (i < line_length)
	{
		if (line[i] != '1' && line[i] != ' ')
			return (E_MAP_IS_OPEN);
		i++;
	}
	return (E_SUCCESS);
}

static t_enum_error	ft_check_middle_lines(char *line,
										char *line_up,
										char *line_down,
										int line_length)
{
	int	i;

	i = 0;
	while (i < line_length)
	{
		if (i == 0 || i == line_length - 1)
		{
			if (line[i] != '1' && line[i] != ' ')
				return (E_MAP_IS_OPEN);
		}
		else
		{
			if (line[i] != '1' && line[i] != ' ')
			{
				if (line_up[i] == ' ' || line_down[i] == ' ' || \
					line[i - 1] == ' ' || line[i + 1] == ' ')
					return (E_MAP_IS_OPEN);
			}	
		}
		i++;
	}
	return (E_SUCCESS);
}

t_enum_error	ft_is_map_open(t_scene *scene)
{
	int				i;
	t_enum_error	error_code;

	i = 0;
	while (i < scene->map_height)
	{
		if (i == 0 || i == scene->map_height - 1)
			error_code = \
				ft_check_first_last_line(scene->map[i], scene->map_length);
		else
			error_code = \
				ft_check_middle_lines(scene->map[i], scene->map[i - 1], \
					scene->map[i + 1], scene->map_length);
		if (error_code != E_SUCCESS)
			return (error_code);
		i++;
	}
	return (E_SUCCESS);
}
