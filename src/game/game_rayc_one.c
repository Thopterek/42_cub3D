/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rayc_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:08:49 by sudaniel          #+#    #+#             */
/*   Updated: 2025/03/17 11:44:43 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	absolute_for_ray(t_raycast	*r, t_player *p, int cc)
{
	r->camera = 2 * cc / (double) WIDTH - 1;
	r->r_direction_x = p->p_direction_x + p->camera_plane_x * r->camera;
	r->r_direction_y = p->p_direction_y + p->camera_plane_y * r->camera;
	r->map_x = (int)p->s_position_x;
	r->map_y = (int)p->s_position_y;
	r->delta_distance_x = fabs(1 / r->r_direction_x);
	r->delta_distance_y = fabs(1 / r->r_direction_y);
	r->hit = 0;
}

static void	counting_steps(t_raycast *r, t_player *p)
{
	if (r->r_direction_x < 0)
	{
		r->step_x = -1;
		r->side_distance_x = (p->s_position_x - r->map_x) * r->delta_distance_x;
	}
	else
	{
		r->step_x = 1;
		r->side_distance_x = (r->map_x + 1.0 - p->s_position_x)
			* r->delta_distance_x;
	}
	if (r->r_direction_y < 0)
	{
		r->step_y = -1;
		r->side_distance_y = (p->s_position_y - r->map_y) * r->delta_distance_y;
	}
	else
	{
		r->step_y = 1;
		r->side_distance_y = (r->map_y + 1.0 - p->s_position_y)
			* r->delta_distance_y;
	}
}

static void	checking_hit_side(char **map, t_raycast *r)
{
	while (r->hit == 0)
	{
		if (r->side_distance_x < r->side_distance_y)
		{
			r->side_distance_x += r->delta_distance_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_distance_y += r->delta_distance_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
	if (r->side == 0)
		r->p_wall_distance = r->side_distance_x - r->delta_distance_x;
	else
		r->p_wall_distance = r->side_distance_y - r->delta_distance_y;
}

static void	floor_ceiling(t_info *i)
{
	int			x;
	int			y;
	const int	half_h = HEIGHT / 2;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < half_h)
				i->buffer[y][x] = i->graphic->ceiling;
			else
				i->buffer[y][x] = i->graphic->floor;
			x++;
		}
		y++;
	}
}

void	raycaster(void	*param)
{
	int		cc;
	t_info	*info;

	cc = 0;
	info = (t_info *)param;
	ft_memset(info->img->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	floor_ceiling(info);
	while (cc < WIDTH)
	{
		absolute_for_ray(info->raycast, info->player, cc);
		counting_steps(info->raycast, info->player);
		checking_hit_side(info->map, info->raycast);
		calc_wall_height(info->draw, info->raycast);
		calc_wall_hit(info->draw, info->raycast, info);
		fill_colors(info->draw, info, cc);
		cc++;
	}
	draw_buffer(info, info->draw);
}
