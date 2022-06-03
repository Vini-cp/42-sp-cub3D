/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:48:39 by vcordeir          #+#    #+#             */
/*   Updated: 2022/06/03 23:48:48 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_buffer(int **buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
