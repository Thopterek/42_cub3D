/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_look_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:21:10 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/11 14:08:54 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	error_mlx(void)
{
	ft_printf("Error: mlx initialization failed\n");
	ft_printf("check: if 'make install-deps' was run\n");
	bin_malloc(-1);
	exit(INITIAL);
}

void	error_img(t_info *info)
{
	ft_printf("Error: creating the main image failed\n");
	ft_printf("check: the of everything before initialization\n");
	mlx_terminate(info->mlx);
	bin_malloc(-1);
	exit(INITIAL);
}
