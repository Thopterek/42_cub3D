/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:05:29 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/10 16:17:17 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	cc;
	int	conversion;
	int	check;

	cc = 0;
	conversion = 0;
	check = 1;
	while (ft_isspace(str[cc]) == 0)
		cc++;
	if (str[cc] == '+' || str[cc] == '-')
	{
		if (str[cc] == '-')
			check = -1;
		cc++;
	}
	while (str[cc] >= 48 && str[cc] <= 57)
	{
		conversion = conversion * 10 + str[cc] - '0';
		cc++;
	}
	return (conversion * check);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	int my;
// 	int og;
// 	char *test = "     	   -123456789$a123";
// 	my = ft_atoi(test);
// 	og = atoi(test);
// 	printf("Result of my FT:\n%d\n", my);
// 	printf("Result of OriGinal:\n%d\n", og);
// }