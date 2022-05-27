/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 04:11:02 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 04:12:50 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_exit_hook(t_game_set *game_set)
{
	mlx_destroy_window((game_set->window)->mlx, (game_set->window)->win);
	ft_free(game_set);
	exit(0);
}
