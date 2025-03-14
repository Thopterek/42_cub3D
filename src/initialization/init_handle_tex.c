/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handle_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:08:47 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/14 18:21:28 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	clean_textures(t_info *i, int to_clean)
{
	while (to_clean > 0)
	{
		to_clean--;
		mlx_delete_texture(i->texture[to_clean]);
	}
}

void	handle_textures(t_info *info)
{
	t_graphic	*g;

	g = info->graphic;
	info->texture[0] = mlx_load_png(g->north_path);
	if (info->texture[0] == NULL)
		error_tex(info, 0);
	info->texture[1] = mlx_load_png(g->west_path);
	if (info->texture[1] == NULL)
		error_tex(info, 1);
	info->texture[2] = mlx_load_png(g->east_path);
	if (info->texture[2] == NULL)
		error_tex(info, 2);
	info->texture[3] = mlx_load_png(g->south_path);
	if (info->texture[3] == NULL)
		error_tex(info, 3);
}
