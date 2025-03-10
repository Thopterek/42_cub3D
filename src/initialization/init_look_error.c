/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_look_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:21:10 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/10 18:27:17 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	error_mlx(void)
{
	ft_printf("Error: mlx initialization failed\n");
	ft_printf("check: '%s'\n", mlx_strerror(mlx_errno));
	bin_malloc(-1);
	exit(INITIAL);
}
