/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:34:26 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/25 14:41:17 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*loop_logic(char *str, unsigned int copy,
		unsigned int counter, char cc)
{
	int	first;

	first = 0;
	while (copy != 0)
	{
		if (first == 0)
		{
			str[counter] = '\0';
			first++;
		}
		if (copy % 16 < 10)
			str[counter - 1] = copy % 16 + '0';
		else if (cc == 'X')
			str[counter - 1] = copy % 16 - 10 + 'A';
		else
			str[counter - 1] = copy % 16 - 10 + 'a';
		copy = copy / 16;
		counter--;
	}
	return (str);
}

static int	memory_cc(unsigned int n, int counter)
{
	while (n != 0)
	{
		counter++;
		n = n / 16;
	}
	return (counter);
}

char	*ft_hex_itoa(unsigned int n, char cc)
{
	unsigned int	copy;
	unsigned int	counter;
	char			*str;

	counter = 0;
	copy = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		copy *= -1;
	counter = memory_cc(n, counter);
	str = ft_calloc(counter + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (loop_logic(str, copy, counter, cc));
}
