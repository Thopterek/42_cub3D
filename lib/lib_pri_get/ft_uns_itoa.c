/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:05:39 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/25 10:24:49 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*loop_logic(char *str, unsigned int copy, unsigned int cc)
{
	int	first;

	first = 0;
	while (copy != 0)
	{
		if (first == 0)
		{
			first++;
			str[cc] = '\0';
		}
		str[cc - 1] = copy % 10 + '0';
		copy = copy / 10;
		cc--;
	}
	return (str);
}

static int	memory_cc(unsigned int n, unsigned int cc)
{
	while (n != 0)
	{
		cc++;
		n = n / 10;
	}
	return (cc);
}

char	*ft_uns_itoa(unsigned int n)
{
	unsigned int	cc;
	unsigned int	copy;
	char			*str;

	cc = 0;
	copy = n;
	if (n == 0)
		return (ft_strdup("0"));
	cc = memory_cc(n, cc);
	str = ft_calloc(cc + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (loop_logic(str, copy, cc));
}
