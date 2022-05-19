/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:56:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/19 03:20:37 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_to_image(void **img, char *path, t_window *window)
{
	*img = mlx_xpm_file_to_image(window->mlx, path, &window->img_width, &window->img_height);
}

static void	ft_build_images(t_assets *assets, t_window *window)
{
	ft_to_image(&assets->player, "./assets/player.xpm", window);
	ft_to_image(&assets->wall, "./assets/wall.xpm", window);
	ft_to_image(&assets->background, "./assets/background.xpm", window);
}

void	ft_load_window(t_game_set *game_set)
{
	t_window	*window;
	t_assets	*assets;

	game_set->window = malloc(sizeof(t_window));
	window = game_set->window;
	game_set->assets = malloc(sizeof(t_assets));
	assets = game_set->assets;

	window->mlx = mlx_init();
	if (window->mlx == NULL)
		ft_print_error(E_MLX, game_set, ft_free);
	window->win = mlx_new_window(window->mlx, LENGTH, HEIGHT, "Cub3D");
	if (window->win == NULL)
		ft_print_error(E_MLX_WIN, game_set, ft_free);
	ft_build_images(assets, window);
}
