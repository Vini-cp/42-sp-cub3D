/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:14:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/20 20:18:01 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_WIDTH 10
# define PLAYER_HEIGHT 10
# define WALK_SPEED 1.0f
# define ROT_SPEED 0.1f

typedef struct s_player
{
	float	x;
	float	y;
	char	initial_direction;
	int		turn_direction;
    int		walk_direction;
    float	rotation_angle;
}	t_player;

#endif
