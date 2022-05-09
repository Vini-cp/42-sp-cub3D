/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 03:43:27 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/09 03:58:03 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*ft_search_error(int error_code)
{
	if (error_code == E_INVALID_INPUT)
		return ("Invalid input, it should have only the map path");
	else if (error_code == E_INVALID_FILE_EXTENSION)
		return ("File extension must be '.cub'");
	return ("No message error with this code.");
}

t_enum_error	ft_print_error(int error_code)
{
	if (error_code == E_SUCCESS)
		return (E_SUCCESS);
	printf("Error\n%s\n", ft_search_error(error_code));
	return (error_code);
}
