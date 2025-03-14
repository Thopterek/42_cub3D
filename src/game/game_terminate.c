/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_terminate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:07:34 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/14 14:13:23 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	terminate_game(t_info *info)
{
	mlx_terminate(info->mlx);
	bin_malloc(-1);
	exit(EXIT_SUCCESS);
}
