/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:08:19 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/17 10:36:48 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static bool	check_collision(double c_x, double c_y, double r_x, double r_y)
{
	const double	closest_x = fmax(r_x, fmin(c_x, r_x + 1.0));
	const double	closest_y = fmax(r_y, fmin(c_y, r_y + 1.0));
	const double	distance_x = c_x - closest_x;
	const double	distance_y = c_y - closest_y;
	const double	result = distance_x * distance_x + distance_y * distance_y;

	if (result < (PLAYER_RADIUS * PLAYER_RADIUS))
		return (true);
	return (false);
}

static int	is_colliding_with_walls(double new_x, double new_y, char **map)
{
	const int	map_x = (int)new_x;
	const int	map_y = (int)new_y;
	int			y;
	int			x;

	y = map_y - 1;
	while (y <= map_y + 1)
	{
		x = map_x - 1;
		while (x <= map_x + 1)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && map[y][x] == '1')
			{
				if (check_collision(new_x, new_y, x, y))
					return (EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

static void	update_player_pos(mlx_key_data_t k, t_player *p,
		double *new_x, double *new_y)
{
	if (k.key == MLX_KEY_W && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
	{
		(*new_x) += p->p_direction_x * p->move_speed;
		(*new_y) += p->p_direction_y * p->move_speed;
	}
	if (k.key == MLX_KEY_S && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
	{
		(*new_x) -= p->p_direction_x * p->move_speed;
		(*new_y) -= p->p_direction_y * p->move_speed;
	}
	if (k.key == MLX_KEY_A && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
	{
		(*new_x) -= p->p_direction_y * p->move_speed;
		(*new_y) += p->p_direction_x * p->move_speed;
	}
	if (k.key == MLX_KEY_D && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
	{
		(*new_x) += p->p_direction_y * p->move_speed;
		(*new_y) -= p->p_direction_x * p->move_speed;
	}
}

void	handling_wasd(mlx_key_data_t k, t_player *p, char **map)
{
	double	new_x;
	double	new_y;

	new_x = p->s_position_x;
	new_y = p->s_position_y;
	update_player_pos(k, p, &new_x, &new_y);
	if (is_colliding_with_walls(new_x, new_y, map) == EXIT_SUCCESS)
	{
		p->s_position_x = new_x;
		p->s_position_y = new_y;
	}
}
