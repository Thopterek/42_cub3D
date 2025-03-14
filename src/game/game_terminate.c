/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_terminate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:07:34 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/14 17:16:29 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	terminate_game(t_info *info)
{
	clean_textures(info, 4);
	mlx_delete_image(info->mlx, info->img);
	mlx_terminate(info->mlx);
	bin_malloc(-1);
	exit(EXIT_SUCCESS);
}
