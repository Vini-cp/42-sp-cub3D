/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:24:00 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 04:24:31 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game_set	game_set;

	ft_check_input(argc, argv);
	ft_get_all_infos(argv[1], &game_set);
	ft_assets_checker(&game_set);
	ft_map_checker(argv[1], &game_set);
	ft_load_player(&game_set);
	ft_load_window(&game_set);
	ft_build_images(&game_set);
	ft_game_loop(&game_set);
	ft_free(&game_set);
	return (0);
}
