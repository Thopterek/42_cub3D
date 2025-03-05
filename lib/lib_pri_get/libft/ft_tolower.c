/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:44:59 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 13:06:45 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper_m(int cc)
{
	if (cc >= 65 && cc <= 90)
		return (cc);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper_m(c) != 0)
	{
		return (c + 32);
	}
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// char cc = 'G';
// printf("%c\n", ft_tolower(cc));
// char t1 = 'a';
// printf("%c\n", ft_tolower(t1));
// char t2 = '7';
// printf("%c\n", ft_tolower(t2));
// printf("thats OG\n%c\n", tolower(cc));
// printf("%c\n", tolower(t1));
// printf("%c\n", tolower(t2));
// }