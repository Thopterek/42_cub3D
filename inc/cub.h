/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:41:48 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/14 11:03:08 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/lib_pri_get/ft_printf.h"
# include "../lib/bin_malloc/bin_malloc.h"
# include "pars.h"
# include "init.h"

/*
	enums for error handling
	setting the exit codes
	- parsing (start)
	- initialization (middle)
	- game output (end)
*/
typedef enum s_errors
{
	PARSING = 1,
	INITIAL = 2,
	GAME = 3
}	t_errors;

/*
	main functions of the program:
	- raycasting
	- key hooks
*/
void	raycaster(void	*param);
void	key_hook(mlx_key_data_t keydata, void *param);

#endif