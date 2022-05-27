/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:07:10 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 04:12:07 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_game_loop(t_game_set *game_set)
{
	t_window	*window;

	window = game_set->window;
	mlx_hook(window->win, 2, (1L << 0), ft_key_press, game_set);
	mlx_hook(window->win, 3, (1L << 1), ft_key_release, game_set);
	mlx_hook(window->win, 6, (1L << 6), ft_mouse_move, game_set);
	mlx_hook(window->win, 8, (1L << 5), ft_mouse_exit, game_set);
	mlx_hook(window->win, 17, 0L, ft_exit_hook, game_set);
	mlx_loop_hook(window->mlx, ft_update, game_set);
	mlx_loop(window->mlx);
}
