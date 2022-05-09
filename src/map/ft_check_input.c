/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 03:37:22 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/09 03:46:22 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_enum_error	ft_check_file_extension(char *file_name)
{
	char	*extension;

	extension = (char *) &file_name[(ft_strlen(file_name) - 4)];
	if (ft_strncmp(extension, ".cub", 4) == 0)
		return (E_SUCCESS);
	return (E_INVALID_FILE_EXTENSION);
}

t_enum_error	ft_check_input(int argc, char **argv)
{
	t_enum_error	error_code;

	if (argc != 2)
		return (ft_print_error(E_INVALID_INPUT));
	error_code = ft_check_file_extension(argv[1]);
	if (error_code != E_SUCCESS)
		return (ft_print_error(E_INVALID_FILE_EXTENSION));
	return (E_SUCCESS);
}
