/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:37:05 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/23 16:45:52 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define FOV_ANGLE 60
# define FLT_MAX 1000000000

typedef struct s_ray_helper
{
	float	xintercept;
	float	yintercept;
	float	distance;
	float	xstep;
	float	ystep;
	int		found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_content;
	float	next_touch_x;
	float	next_touch_y;
	float	x_to_check;
	float	y_to_check;
}	t_ray_helper;

typedef struct s_ray
{
	float			angle;
	float			wall_hit_x;
	float			wall_hit_y;
	float			distance;
	int				was_hit_vertical;
	int				wall_hit_content;
	int				is_ray_facing_up;
	int				is_ray_facing_down;
	int				is_ray_facing_left;
	int				is_ray_facing_right;
	t_ray_helper	horizontal;
	t_ray_helper	vertical;
}	t_ray;

#endif
