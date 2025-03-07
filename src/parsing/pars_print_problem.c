/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_print_problem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:20:29 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/07 15:30:08 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	error_char(char c)
{
	ft_printf("Error: invalid character in the map\n");
	ft_printf("check: found '%c' only 10NSEW are valid\n", c);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_orient(int orient)
{
	ft_printf("Error: wrong number of players on the map\n");
	ft_printf("check: should be only 1, but were '%d'\n", orient);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_walls(int space)
{
	ft_printf("Error: map is not closed properly\n");
	ft_printf("check: there were '%d' unclosed spaces\n", space);
	bin_malloc(-1);
	exit(PARSING);
}
