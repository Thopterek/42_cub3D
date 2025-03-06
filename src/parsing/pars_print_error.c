/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_print_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:34:51 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 18:58:45 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	error_ac(void)
{
	ft_printf("Error: wrong number of arguments\n");
	ft_printf("usage: ./cub3D [file in map].cub\n");
	exit(PARSING);
}

void	error_format(char **av)
{
	ft_printf("Error: wrong format of the map\n");
	ft_printf(".cub in '%s' not found\n", av[1]);
	exit(PARSING);
}

void	error_path(char *path)
{
	ft_printf("Error: can't access the map file\n");
	ft_printf("path: '%s' failed\n", path);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_png(char *line, char *actual)
{
	ft_printf("Error: can't access the png file\n");
	ft_printf("check: '%s' for typos\n", line);
	if (actual != NULL)
		free(actual);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_element(void)
{
	ft_printf("Error: texture count is wrong\n");
	ft_printf("check: number of NO/SO/WE/EA in map\n");
	bin_malloc(-1);
	exit(PARSING);
}
