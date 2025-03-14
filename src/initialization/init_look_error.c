/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_look_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:21:10 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/14 16:26:35 by ndziadzi         ###   ########.fr       */
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
	ft_printf("check: check size definitions before initialization\n");
	mlx_terminate(info->mlx);
	bin_malloc(-1);
	exit(INITIAL);
}

void	error_tex(t_info *info, int c)
{
	ft_printf("Error: mlx_load_png failed\n");
	ft_printf("check: the png '%d' used for textures\n", c);
	clean_textures(info, c);
	mlx_terminate(info->mlx);
	bin_malloc(-1);
	exit(INITIAL);
}
