/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:21 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/17 12:33:15 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	calculation_right(t_player *p)
{
	const double	old_dir_x = p->p_direction_x;
	const double	old_plane_x = p->camera_plane_x;

	p->p_direction_x = p->p_direction_x * cos(-p->rot_speed)
		- p->p_direction_y * sin(-p->rot_speed);
	p->p_direction_y = old_dir_x * sin(-p->rot_speed)
		+ p->p_direction_y * cos(-p->rot_speed);
	p->camera_plane_x = p->camera_plane_x * cos(-p->rot_speed)
		- p->camera_plane_y * sin(-p->rot_speed);
	p->camera_plane_y = old_plane_x * sin(-p->rot_speed)
		+ p->camera_plane_y * cos(-p->rot_speed);
}

static void	calc_left(t_player *p)
{
	const double	old_dir_x = p->p_direction_x;
	const double	old_plane_x = p->camera_plane_x;

	p->p_direction_x = p->p_direction_x * cos(p->rot_speed)
		- p->p_direction_y * sin(p->rot_speed);
	p->p_direction_y = old_dir_x * sin(p->rot_speed)
		+ p->p_direction_y * cos(p->rot_speed);
	p->camera_plane_x = p->camera_plane_x * cos(p->rot_speed)
		- p->camera_plane_y * sin(p->rot_speed);
	p->camera_plane_y = old_plane_x * sin(p->rot_speed)
		+ p->camera_plane_y * cos(p->rot_speed);
}

static void	rotating_view(mlx_key_data_t k, t_player *p)
{
	if (k.key == MLX_KEY_RIGHT
		&& (k.action == MLX_PRESS || k.action == MLX_REPEAT))
	{
		calculation_right(p);
	}
	if (k.key == MLX_KEY_LEFT
		&& (k.action == MLX_PRESS || k.action == MLX_REPEAT))
	{
		calc_left(p);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	handling_wasd(keydata, info->player, info->map);
	rotating_view(keydata, info->player);
	if (keydata.key == MLX_KEY_ESCAPE)
		terminate_game(info);
}
