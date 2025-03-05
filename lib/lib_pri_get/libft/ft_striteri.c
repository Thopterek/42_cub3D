/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:40:49 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 09:04:59 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	cc;
	char	*new;

	cc = 0;
	new = s;
	while (cc < ft_strlen(new))
	{
		f(cc, &s[cc]);
		cc++;
	}
}
