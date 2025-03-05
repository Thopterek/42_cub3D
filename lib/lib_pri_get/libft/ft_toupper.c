/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:33:42 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 13:06:57 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower_m(int cc)
{
	if (cc >= 97 && cc <= 122)
		return (cc);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower_m(c) != 0)
		return (c - 32);
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// char cc = 'h';
// printf("Thats my FT\n%c\n", ft_toupper(cc));
// printf("Thats Original\n%c\n", toupper(cc));
// }