/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_print_problem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:20:29 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/07 11:54:21 by ndziadzi         ###   ########.fr       */
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
	ft_printf("Error: too many player positions found on map\n");
	ft_printf("check: should be only 1, but were '%d'\n", orient);
	bin_malloc(-1);
	exit(PARSING);
}
