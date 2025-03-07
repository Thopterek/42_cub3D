/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_print_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:56:15 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/07 11:22:30 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	error_rgb(int cc, char *line, int fd, int flag)
{
	ft_printf("Error: not in RGB format, should be 3 numbers\n");
	if (flag == FLOOR)
		ft_printf("check: there were '%d' numbers in floor\n", cc);
	else
		ft_printf("check: there were '%d' numbers in ceiling\n", cc);
	if (line != NULL)
		free(line);
	close(fd);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_range(int tmp, char *line, int fd, int flag)
{
	ft_printf("Error: number '%d' is not in RGB range\n", tmp);
	if (flag == FLOOR)
		ft_printf("check: colors in floor should be between 0 and 255\n");
	else
		ft_printf("check: colors in ceiling should be between 0 and 255\n");
	if (line != NULL)
		free(line);
	close(fd);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_color_count(int floor, int ceiling)
{
	ft_printf("Error: count of indetifiers for colors are wrong\n");
	ft_printf("check: there are '%d' floors and '%d' ceilings\n",
		floor, ceiling);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_nothing(void)
{
	ft_printf("Error: map not found, there were no walls\n");
	ft_printf("check: every valid map should have char '1'\n");
	bin_malloc(-1);
	exit(PARSING);
}
