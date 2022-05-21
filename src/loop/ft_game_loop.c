/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:07:10 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 21:47:02 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_exit_hook(t_game_set *game_set)
{
	mlx_destroy_window((game_set->window)->mlx, (game_set->window)->win);
	ft_free(game_set);
	exit(0);
}

static int	ft_key_press(int keycode, t_game_set *game_set)
{
	t_player	*player;

	player = game_set->player;
	if (keycode == ESC)
		ft_exit_hook(game_set);
	if (keycode == UP)
		player->walk_direction = -1;
	if (keycode == DOWN)
		player->walk_direction = +1;
	if (keycode == LEFT)
		player->side_direction = -1;
	if (keycode == RIGHT)
		player->side_direction = +1;
	if (keycode == LEFT_ARROW)
		player->turn_direction = -1;
	if (keycode == RIGHT_ARROW)
		player->turn_direction = +1;
	return (0);
}

static int	ft_key_release(int keycode, t_game_set *game_set)
{
	t_player	*player;

	player = game_set->player;
	if (keycode == UP)
		player->walk_direction = 0;
	if (keycode == DOWN)
		player->walk_direction = 0;
	if (keycode == LEFT)
		player->side_direction = 0;
	if (keycode == RIGHT)
		player->side_direction = 0;
	if (keycode == LEFT_ARROW)
		player->turn_direction = 0;
	if (keycode == RIGHT_ARROW)
		player->turn_direction = 0;
	return (0);
}

void	ft_game_loop(t_game_set *game_set)
{
	t_window	*window;

	window = game_set->window;
	mlx_hook(window->win, 2, (1L<<0), ft_key_press, game_set);
	mlx_hook(window->win, 3, (1L<<1), ft_key_release, game_set);
	mlx_hook(window->win, 17, 0L, ft_exit_hook, game_set);
	mlx_loop_hook(window->mlx, ft_update, game_set);
	mlx_loop(window->mlx);
}
