/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:56:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/22 02:30:14 by vcordeir         ###   ########.fr       */
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
	window->win = mlx_new_window(window->mlx, LENGTH, HEIGHT, "Cub3D");
	if (window->win == NULL)
		ft_print_error(E_MLX_WIN, game_set, ft_free);
}
