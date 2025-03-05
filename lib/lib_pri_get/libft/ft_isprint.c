/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:51:10 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 12:48:28 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// char cc = 'G';
// char t = '\0';
// printf("This is my FT:\n%d\n", ft_isprint(cc));
// printf("This is my FT:\n%d\n", ft_isprint(t));
// printf("This is OriGinal:\n%d\n", isprint(cc));
// printf("This is OriGinal:\n%d\n", isprint(t));
// }