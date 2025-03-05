/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:24:13 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 12:47:39 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper_c(int c)
{
	if (c >= 65 && c <= 90)
		return (c);
	return (0);
}

static int	ft_islower_c(int c)
{
	if (c >= 97 && c <= 122)
		return (c);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((ft_islower_c(c) || ft_isupper_c(c)) > 0)
		return (c);
	return (0);
}

// #include <ctype.h>
// int main(void)
// {
// char correct = 'g';
// char wrong = '*';
// printf("This is my FT:\n%d\n", ft_isalpha(correct));
// printf("This is my FT:\n%d\n", ft_isalpha(wrong));
// printf("This is OriGinal:\n%d\n", isalpha(correct));
// printf("This is OriGinal:\n%d\n", isalpha(wrong));
// }