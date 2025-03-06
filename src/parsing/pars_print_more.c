/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_print_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:56:15 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/06 12:36:24 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	error_updown(char *no_newline, char flag, char *line)
{
	ft_printf("Error: the color for '%c' is not set up\n", flag);
	ft_printf("check: '%s' for typos\n", no_newline);
	if (line != NULL)
		free(line);
	bin_malloc(-1);
	exit(PARSING);
}

void	error_rgb(int cc, char *line)
{
	ft_printf("Error: not in RGB format, should be 3 numbers\n");
	ft_printf("check: there were '%d' numbers\n", cc);
	if (line != NULL)
		free(line);
	bin_malloc(-1);
	exit(PARSING);
}
