/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:24:00 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/11 23:59:00 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game_set	game_set;

	if (ft_check_input(argc, argv) != E_SUCCESS)
		return (ft_free(&game_set));
	return (ft_free(&game_set));
}
