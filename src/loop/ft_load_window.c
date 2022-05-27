/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:56:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/27 23:29:10 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_load_window(t_game_set *game_set)
{
	t_window	*window;

	game_set->window = malloc(sizeof(t_window));
	window = game_set->window;
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		ft_print_error(E_MLX, game_set, ft_free);
	mlx_get_screen_size(window->mlx, &game_set->window_width, \
		&game_set->window_height);
	printf("W: %d | H: %d\n", game_set->window_width, game_set->window_height);
	window->win = mlx_new_window(window->mlx, game_set->window_width, \
		game_set->window_height, "Cub3D");
	if (window->win == NULL)
		ft_print_error(E_MLX_WIN, game_set, ft_free);
	game_set->number_of_rays = game_set->window_width;
	game_set->rays = malloc(game_set->number_of_rays * sizeof(t_ray));
}
