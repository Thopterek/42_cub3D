/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rayc_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:13:41 by sudaniel          #+#    #+#             */
/*   Updated: 2025/03/17 11:44:57 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	calc_wall_height(t_draw *d, t_raycast *r)
{
	const int	half_h = HEIGHT / 2;

	d->line_height = (int)(HEIGHT / r->p_wall_distance);
	d->draw_start = -d->line_height / 2 + half_h;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + half_h;
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
		if (r->r_direction_y > 0)
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
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)TEX_WIDTH);
	if (r->side == 0 && r->r_direction_x > 0)
		d->tex_x = TEX_WIDTH - d->tex_x - 1;
	if (r->side == 1 && r->r_direction_y < 0)
		d->tex_x = TEX_WIDTH - d->tex_x - 1;
	d->step = 1.0 * TEX_HEIGHT / d->line_height;
	d->tex_pos = (d->draw_start - HEIGHT / 2 + d->line_height / 2) * d->step;
}

void	fill_colors(t_draw *d, t_info *info, int x)
{
	int	y;	

	y = d->draw_start;
	d->pixel_data = (uint32_t *)info->texture[d->tex_num]->pixels;
	while (y < d->draw_end)
	{
		d->tex_y = (int)d->tex_pos & (TEX_HEIGHT - 1);
		d->tex_pos += d->step;
		d->color = d->pixel_data[d->tex_y * TEX_WIDTH + d->tex_x];
		info->buffer[y][x] = d->color;
		y++;
	}
}

void	draw_buffer(t_info *i, t_draw *d)
{
	int	y;
	int	x;
	int	index;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			d->color = i->buffer[y][x];
			index = (y * WIDTH + x) * 4;
			i->img->pixels[index] = (d->color >> 16) & 0xFF;
			i->img->pixels[index + 1] = (d->color >> 8) & 0xFF;
			i->img->pixels[index + 2] = d->color & 0xFF;
			i->img->pixels[index + 3] = 255;
			x++;
		}
		y++;
	}
}
