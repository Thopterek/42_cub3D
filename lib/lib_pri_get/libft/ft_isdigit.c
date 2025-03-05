/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:56:49 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/10 08:52:29 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// char correct = '7';
// char wrong = '*';
// printf("This is my FT:\n%d\n", ft_isdigit(correct));
// printf("This is my FT:\n%d\n", ft_isdigit(wrong));
// printf("This is OriGinal:\n%d\n", isdigit(correct));
// printf("This is OriGinal:\n%d\n", isdigit(wrong));
// }
