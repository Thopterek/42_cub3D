/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:31:05 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/25 14:41:41 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*loop_logic(char *str, unsigned long copy, unsigned long counter)
{
	int	first;

	first = 0;
	while (copy != 0)
	{
		if (first == 0)
		{
			str[counter] = '\0';
			str[0] = '0';
			str[1] = 'x';
			first++;
		}
		if (copy % 16 < 10)
			str[counter - 1] = copy % 16 + '0';
		else
			str[counter - 1] = copy % 16 - 10 + 'a';
		copy = copy / 16;
		counter--;
	}
	return (str);
}

static int	memory_cc(unsigned long n, int counter)
{
	while (n != 0)
	{
		counter++;
		n = n / 16;
	}
	return (counter);
}

char	*ft_ptr_itoa(unsigned long n)
{
	unsigned long	copy;
	unsigned long	counter;
	char			*str;

	counter = 0;
	copy = n;
	if (n == 0)
		return (ft_strdup("0x0"));
	if (n < 0)
		copy *= -1;
	counter = memory_cc(n, counter + 2);
	str = ft_calloc(counter + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (loop_logic(str, copy, counter));
}
