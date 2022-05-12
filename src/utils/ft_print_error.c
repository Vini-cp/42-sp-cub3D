/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 03:43:27 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 01:40:50 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*ft_search_error(int error_code)
{
	if (error_code == E_INVALID_INPUT)
		return ("Invalid input, it should have only the map path");
	else if (error_code == E_INVALID_FILE_EXTENSION)
		return ("File extension must be '.cub'");
	else if (error_code == E_FILE_DOES_NOT_EXISTS)
		return ("Try to open a file that does not exists");
	else if (error_code == E_MALLOC)
		return ("No more space on the heap");
	else if (error_code == E_MAP_HAS_EMPTY_LINES)
		return ("The map must not be separeted by empy lines");
	else if (error_code == E_MAP_HAS_INVALID_CHARS)
		return ("There are only 6 possible characters: 0, 1, N, S, E and W");
	else if (error_code == E_MAP_IS_OPEN)
		return ("The map must be closed/surrounded by walls");
	else if (error_code == E_MAP_HAS_NO_SPAWNING_POSITION)
		return ("The map has no player position");
	else if (error_code == E_NULL_ASSET)
		return ("Assets path must not be null");
	return ("No message error with this code.");
}

t_enum_error	ft_print_error(int error_code)
{
	if (error_code == E_SUCCESS)
		return (E_SUCCESS);
	printf("Error\n%s\n", ft_search_error(error_code));
	return (error_code);
}
