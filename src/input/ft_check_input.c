/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 03:37:22 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/13 22:43:37 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_check_file_extension(char *file_name)
{
	char	*extension;

	extension = (char *) &file_name[(ft_strlen(file_name) - 4)];
	if (ft_strncmp(extension, ".cub", 4) != 0)
		ft_print_error(E_INVALID_FILE_EXTENSION, NULL, NULL);
}

void	ft_check_input(int argc, char **argv)
{
	if (argc != 2)
		ft_print_error(E_INVALID_INPUT, NULL, NULL);
	ft_check_file_extension(argv[1]);
}
