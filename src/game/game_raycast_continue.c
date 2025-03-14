/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycast_continue.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:13:41 by sudaniel          #+#    #+#             */
/*   Updated: 2025/03/14 17:03:50 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	calc_wall_height(t_draw *d, t_raycast *r)
{
	d->line_height = (int)(HEIGHT / r->p_wall_distance);
	d->draw_start = -d->line_height / 2 + HEIGHT / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + HEIGHT / 2;
	if (d->draw_end >= HEIGHT)
		d->draw_end = HEIGHT - 1;
	if (r->side == 0)
	{
		if (r->r_direction_x > 0)
			d->tex_num = WEST;
		else
			d->tex_num = EAST;
	}
	else
	{
		if (r->r_direction_x > 0)
			d->tex_num = SOUTH;
		else
			d->tex_num = NORTH;
	}
}

void	calc_wall_hit(t_draw *d, t_raycast *r, t_info *info)
{
	if (r->side == 0)
		d->wall_x = info->player->s_position_y
			+ r->p_wall_distance * r->r_direction_y;
	else
		d->wall_x = info->player->s_position_x
			+ r->p_wall_distance * r->r_direction_x;
	d->wall_x = floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)(TEX_WIDTH));
	if (r->side == 0 && r->r_direction_x > 0)
		d->tex_x = TEX_WIDTH - d->tex_x - 1;
	if (r->side == 1 && r->r_direction_y < 0)
		d->tex_x = TEX_WIDTH - d->tex_x - 1;
	d->step = 1.0 * TEX_HEIGHT / d->line_height;
	d->tex_pos = (d->draw_start - HEIGHT / 2 + d->line_height / 2) * d->step;
}

void	fill_colors(t_draw *d, t_raycast *r, t_info *info, int x)
{
	int	y;	

	y = d->draw_start;
	while (y < d->draw_end)
	{
		d->tex_y = (int)d->tex_pos & (TEX_HEIGHT - 1);
		d->tex_pos = d->step;
		d->pixel_data = (uint32_t *)info->texture[d->tex_num]->pixels;
		d->color = d->pixel_data[d->tex_y * TEX_WIDTH + d->tex_x];
		if (r->side == 1)
			d->color = (d->color >> 1) & 8355711;
		info->buffer[y][x] = d->color;
		y++;
	}
}
