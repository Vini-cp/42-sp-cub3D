/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:42:10 by vcordeir          #+#    #+#             */
/*   Updated: 2022/05/24 23:47:35 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

typedef struct s_line
{
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		step;
	float	derror;
	float	error;
}	t_line;

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_initialize_line(t_line *line, t_player *player, t_ray *ray)
{
	line->x0 = player->x;
	line->y0 = player->y;
	line->x1 = ray->wall_hit_x;
	line->y1 = ray->wall_hit_y;
	line->step = 0;
}

// static void	ft_initialize(t_line *line, t_player *player, t_ray_helper *ray)
// {
// 	line->x0 = player->x;
// 	line->y0 = player->y;
// 	line->x1 = ray->wall_hit_x;
// 	line->y1 = ray->wall_hit_y;
// 	line->step = 0;
// }

static void	ft_check_deltas(t_line *line)
{
	if (abs(line->x0 - line->x1) < abs(line->y0 - line->y1))
	{
		ft_swap(&line->x0, &line->y0);
		ft_swap(&line->x1, &line->y1);
		line->step = 1;
	}
	if (line->x0 > line->x1)
	{
		ft_swap(&line->x0, &line->x1);
		ft_swap(&line->y0, &line->y1);
	}
	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
}

static void	ft_print_line(t_line *line, t_window *window, int color)
{
	line->derror = ft_abs_float((1.0 * line->dy) / line->dx);
	line->error = 0;
	line->y = line->y0;
	line->x = line->x0;
	while (line->x <= line->x1)
	{
		if (line->step)
			mlx_pixel_put(window->mlx, window->win, line->y, line->x, color);
		else
			mlx_pixel_put(window->mlx, window->win, line->x, line->y, color);
		line->error += line->derror;
		if (line->error > 0.5)
		{
			if (line->y1 > line->y0)
				line->y += 1;
			else
				line->y -= 1;
			line->error -= 1;
		}
		line->x++;
	}
}

void	ft_draw_rays(t_game_set *game_set, int color)
{
	int		strip_id;
	t_line	line;
	t_ray	*ray;

	strip_id = 0;
	ray = game_set->rays;
	while (strip_id < game_set->number_of_rays)
	{
		ft_initialize_line(&line, game_set->player, &ray[strip_id]);
		ft_check_deltas(&line);
		ft_print_line(&line, game_set->window, color);
		// if (ray[strip_id].horizontal.distance != FLT_MAX || ray[strip_id].horizontal.distance != 0)
		// {
		// 	ft_initialize(&line, game_set->player, &ray[strip_id].horizontal);
		// 	ft_check_deltas(&line);
		// 	ft_print_line(&line, game_set->window, color);
		// }
		// ft_initialize(&line, game_set->player, &ray[strip_id].vertical);
		// ft_check_deltas(&line);
		// ft_print_line(&line, game_set->window, BLUE);
		strip_id++;
	}
}
